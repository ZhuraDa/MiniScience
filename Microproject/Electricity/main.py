from dolfin import *

# Create mesh and define function space
mesh = RectangleMesh(Point(-1.0, -1.0), Point(1.0, 1.0), 32, 32)
V = FunctionSpace(mesh, 'Lagrange', 1)

def boundary_D1(x, on_boundary):
    return on_boundary and (x[0] < -1.0 + DOLFIN_EPS)

def boundary_D2(x, on_boundary):
    return on_boundary and (x[0] > 1.0 - DOLFIN_EPS)

def boundary_Z(x, on_boundary):
    return on_boundary and (x[1] < -1.0 + DOLFIN_EPS or x[1] > 1.0 - DOLFIN_EPS)

# Define boundary condition
u_l = Constant(-1.0)
u_r = Constant(1.0)
u_z = Expression('x[0]', degree=2)
bc1 = DirichletBC(V, u_l, boundary_D1)
bc2 = DirichletBC(V, u_r, boundary_D2)
bc3 = DirichletBC(V, u_z, boundary_Z)
# Define variational problem
Phi = Function(V)
v = TestFunction(V)
Lambda = Expression("(100 * exp(-25 * (x[0]*x[0] + x[1]*x[1])) + 1)", degree=2)
a = inner(grad(Phi), grad(v))*Lambda*dx
# Compute solution
solve(a == 0, Phi, [bc1, bc2, bc3])

W = VectorFunctionSpace(mesh, "Lagrange", 1)
# Save solution to file in VTK format
vtkfile = File('elecricity/Phi.pvd')
vtkfile << Phi

E = project(-grad(Phi), W)
file = File("elecricity/field.pvd")
file << E
lambdaa = project(Lambda, V)
file = File("elecricity/lambda.pvd")
file << lambdaa

j = project(-Lambda*grad(Phi), W)
file = File("elecricity/flow.pvd")
file << j

Power = project(inner(j, E), V)
file = File("elecricity/power.pvd")
file << Power

Charge = project(div(E)/(4*3.14), V)
file = File("elecricity/charge.pvd")
file << Charge

phi_const = Expression('x[0]', degree=2)
delta_phi = project(Phi-phi_const, V)
file = File("elecricity/delta_phi.pvd")
file << delta_phi