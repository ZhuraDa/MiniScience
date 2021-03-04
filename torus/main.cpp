#include <set>
#include "gmsh.h"


int main(int argc, char **argv) {
    gmsh::initialize();
    gmsh::model::add("torus");
    double lc = 0.1;
    double R_tor = 4;
    double r_tor = 2;
    double r_obr = 0.8;
    double R_obr = 1;

//как вы могли понять, я страшный человек раз решил написать такой код
    // Две окружности образующие тор
    //малая окружность
    gmsh::model::geo::addPoint(0, 0, 0, lc, 1);
    gmsh::model::geo::addPoint(r_tor, 0, 0, lc, 2);
    gmsh::model::geo::addPoint(-r_tor, 0, 0, lc, 3);
    //потом я догодался переделать эту арку, поэтому теперь она будет закоменчена
    /*gmsh::model::geo::addCircleArc(2, 1, 3, 1);
    gmsh::model::geo::addCircleArc(3, 1, 2, 2);*/
    //большая окружность
    gmsh::model::geo::addPoint(R_tor, 0, 0, lc, 4);
    gmsh::model::geo::addPoint(-R_tor, 0, 0, lc, 5);
    //эту тоже переделал
    /*gmsh::model::geo::addCircleArc(4, 1, 5, 3);
    gmsh::model::geo::addCircleArc(5, 1, 4, 4);*/

    // две маленькие окружности по краям(Внутренние и внешние)
        //две точки центра
    gmsh::model::geo::addPoint(R_tor-R_obr, 0, 0, lc, 11);
    gmsh::model::geo::addPoint(-R_tor+R_obr, 0, 0, lc, 12);

    gmsh::model::geo::addPoint(R_tor-R_obr, 0, R_obr, lc, 13);
    gmsh::model::geo::addPoint(R_tor-R_obr, 0, -R_obr, lc, 14);
    gmsh::model::geo::addPoint(-R_tor+R_obr, 0, R_obr, lc, 15);
    gmsh::model::geo::addPoint(-R_tor+R_obr, 0, -R_obr, lc, 16);
    //первая окружность
    gmsh::model::geo::addCircleArc(13, 11, 4, 5);
    gmsh::model::geo::addCircleArc(4, 11, 14, 6);
    gmsh::model::geo::addCircleArc(14, 11, 2, 7);
    gmsh::model::geo::addCircleArc(2, 11, 13, 8);
    //вторая окружность
    gmsh::model::geo::addCircleArc(15, 12, 3, 9);
    gmsh::model::geo::addCircleArc(3, 12, 16, 10);
    gmsh::model::geo::addCircleArc(16, 12, 5, 11);
    gmsh::model::geo::addCircleArc(5, 12, 15, 12);
    //первая внутренняя окружность
    gmsh::model::geo::addPoint(R_tor-R_obr, 0, r_obr, lc, 17);
    gmsh::model::geo::addPoint(R_tor-R_obr, 0, -r_obr, lc, 18);
    gmsh::model::geo::addPoint(R_tor-R_obr+r_obr, 0, 0, lc, 19);
    gmsh::model::geo::addPoint(R_tor-R_obr-r_obr, 0, 0, lc, 20);
    gmsh::model::geo::addCircleArc(17, 11, 19, 13);
    gmsh::model::geo::addCircleArc(19, 11, 18, 14);
    gmsh::model::geo::addCircleArc(18, 11, 20, 15);
    gmsh::model::geo::addCircleArc(20, 11, 17, 16);


    //вторая внутренняя окружность
    gmsh::model::geo::addPoint(-R_tor+R_obr, 0, r_obr, lc, 21);
    gmsh::model::geo::addPoint(-R_tor+R_obr, 0, -r_obr, lc, 22);
    gmsh::model::geo::addPoint(-R_tor+R_obr-r_obr, 0, 0, lc, 23);
    gmsh::model::geo::addPoint(-R_tor+R_obr+r_obr, 0, 0, lc, 24);
    gmsh::model::geo::addCircleArc(21, 12, 24, 17);
    gmsh::model::geo::addCircleArc(24, 12, 22, 18);
    gmsh::model::geo::addCircleArc(22, 12, 23, 19);
    gmsh::model::geo::addCircleArc(23, 12, 21, 20);
    //центры ещё двух окружностей по которым будем строить тор
    gmsh::model::geo::addPoint(0, R_tor-R_obr, 0, lc, 25);
    gmsh::model::geo::addPoint(0, -R_tor+R_obr, 0, lc, 26);
    //вспомогательные точки
    gmsh::model::geo::addPoint(0, R_tor, 0, lc, 27);
    gmsh::model::geo::addPoint(0, -R_tor, 0, lc, 28);
    gmsh::model::geo::addPoint(0, r_tor, 0, lc, 29);
    gmsh::model::geo::addPoint(0, -r_tor, 0, lc, 30);
    //верхняя окружность
    gmsh::model::geo::addPoint(0, R_tor-R_obr, R_obr, lc, 31);
    gmsh::model::geo::addPoint(0, R_tor-R_obr, -R_obr, lc, 32);
    gmsh::model::geo::addCircleArc(27, 25, 31, 22);
    gmsh::model::geo::addCircleArc(31, 25, 29, 23);
    gmsh::model::geo::addCircleArc(29, 25, 32, 24);
    gmsh::model::geo::addCircleArc(32, 25, 27, 25);
    //верхняя внутренняя окружность
    gmsh::model::geo::addPoint(0, R_tor-R_obr-r_obr, 0, lc, 33);
    gmsh::model::geo::addPoint(0, R_tor-R_obr+r_obr, 0, lc, 34);
    gmsh::model::geo::addPoint(0, R_tor-R_obr, r_obr, lc, 35);
    gmsh::model::geo::addPoint(0, R_tor-R_obr, -r_obr, lc, 36);
    gmsh::model::geo::addCircleArc(33, 25, 35, 26);
    gmsh::model::geo::addCircleArc(35, 25, 34, 27);
    gmsh::model::geo::addCircleArc(34, 25, 36, 28);
    gmsh::model::geo::addCircleArc(36, 25, 33, 29);
    //нижняя окружность
    gmsh::model::geo::addPoint(0, -R_tor+R_obr, R_obr, lc, 37);
    gmsh::model::geo::addPoint(0, -R_tor+R_obr, -R_obr, lc, 38);
    gmsh::model::geo::addCircleArc(37, 26, 30, 30);
    gmsh::model::geo::addCircleArc(30, 26, 38, 31);
    gmsh::model::geo::addCircleArc(38, 26, 28, 32);
    gmsh::model::geo::addCircleArc(28, 26, 37, 33);
    //нижняя внутренняя окружность
    gmsh::model::geo::addPoint(0, -R_tor+R_obr+r_obr, 0, lc, 39);
    gmsh::model::geo::addPoint(0, -R_tor+R_obr-r_obr, 0, lc, 40);
    gmsh::model::geo::addPoint(0, -R_tor+R_obr, r_obr, lc, 41);
    gmsh::model::geo::addPoint(0, -R_tor+R_obr, -r_obr, lc, 42);
    gmsh::model::geo::addCircleArc(39, 26, 41, 34);
    gmsh::model::geo::addCircleArc(41, 26, 40, 35);
    gmsh::model::geo::addCircleArc(40, 26, 42, 36);
    gmsh::model::geo::addCircleArc(42, 26, 39, 37);
    //образующие окружности(большие) тора
    gmsh::model::geo::addPoint(0, 0, -r_obr, lc, 43);
    gmsh::model::geo::addPoint(0, 0, r_obr, lc, 44);
    gmsh::model::geo::addPoint(0, 0, -R_obr, lc, 45);
    gmsh::model::geo::addPoint(0, 0, R_obr, lc, 46);

    gmsh::model::geo::addCircleArc(25, 1, 11, 38);
    gmsh::model::geo::addCircleArc(11, 1, 26, 44);
    gmsh::model::geo::addCircleArc(26, 1, 12, 64);
    gmsh::model::geo::addCircleArc(12, 1, 25, 65);

    gmsh::model::geo::addCircleArc(31, 46, 13, 39);
    gmsh::model::geo::addCircleArc(13, 46, 37, 45);
    gmsh::model::geo::addCircleArc(37, 46, 15, 50);
    gmsh::model::geo::addCircleArc(15, 46, 31, 51);

    gmsh::model::geo::addCircleArc(38, 45, 16, 40);
    gmsh::model::geo::addCircleArc(16, 45, 32, 46);
    gmsh::model::geo::addCircleArc(32, 45, 14, 52);
    gmsh::model::geo::addCircleArc(14, 45, 38, 53);

    gmsh::model::geo::addCircleArc(33, 1, 20, 41);
    gmsh::model::geo::addCircleArc(20, 1, 39, 47);
    gmsh::model::geo::addCircleArc(39, 1, 24, 66);
    gmsh::model::geo::addCircleArc(24, 1, 33, 67);

    gmsh::model::geo::addCircleArc(34, 1, 23, 42);
    gmsh::model::geo::addCircleArc(23, 1, 40, 48);
    gmsh::model::geo::addCircleArc(40, 1, 19, 68);
    gmsh::model::geo::addCircleArc(19, 1, 34, 69);

    gmsh::model::geo::addCircleArc(42, 43, 22, 43);
    gmsh::model::geo::addCircleArc(22, 43, 36, 49);
    gmsh::model::geo::addCircleArc(36, 43, 18, 54);
    gmsh::model::geo::addCircleArc(18, 43, 42, 55);

    gmsh::model::geo::addCircleArc(35, 44, 17, 56);
    gmsh::model::geo::addCircleArc(17, 44, 41, 57);
    gmsh::model::geo::addCircleArc(41, 44, 21, 58);
    gmsh::model::geo::addCircleArc(21, 44, 35, 59);
    //всё соединяем
    //и тут я понял, что жёстко промахнулся и не могу создать замкнутые кривые(((((((((
    //поэтому нужно дополнительные арки, 12 арок я дополнил в пердыдущий код,поэтому нумерация така кривая
    gmsh::model::geo::addCircleArc(2, 1, 29, 1);
    gmsh::model::geo::addCircleArc(29, 1, 3, 60);
    gmsh::model::geo::addCircleArc(3, 1, 30, 2);
    gmsh::model::geo::addCircleArc(30, 1, 2, 61);

    gmsh::model::geo::addCircleArc(4, 1, 27, 3);
    gmsh::model::geo::addCircleArc(27, 1, 5, 4);
    gmsh::model::geo::addCircleArc(5, 1, 28, 62);
    gmsh::model::geo::addCircleArc(28, 1, 4, 63);


    //все curveloops внутреннего тора
    //правый
   gmsh::model::geo::addCurveLoop({35,68,-13,57},1);
   gmsh::model::geo::addCurveLoop({-68,36,-55,-14},2);
   gmsh::model::geo::addCurveLoop({57,-34,-47,16},3);
   gmsh::model::geo::addCurveLoop({55,37,-47,-15},4);
//левый
    gmsh::model::geo::addCurveLoop({-48,20,-58,35},5);
    gmsh::model::geo::addCurveLoop({48,36,43,19},6);
    gmsh::model::geo::addCurveLoop({58,17,-66,34},7);
    gmsh::model::geo::addCurveLoop({66,18,-43,37},8);
//верхний левый
    gmsh::model::geo::addCurveLoop({42,27,59,20},9);
    gmsh::model::geo::addCurveLoop({42,-19,49,-28},10);
    gmsh::model::geo::addCurveLoop({59,-26,-67,-17},11);
    gmsh::model::geo::addCurveLoop({-67,18,49,29},12);
//верхний правый
    gmsh::model::geo::addCurveLoop({69,-27,56,13},13);
    gmsh::model::geo::addCurveLoop({69,28,54,-14},14);
    gmsh::model::geo::addCurveLoop({-56,-26,41,16},15);
    gmsh::model::geo::addCurveLoop({41,-15,-54,29},16);
    //все curveloops внешнего тора
//правый
    gmsh::model::geo::addCurveLoop({63,-5,45,-33},17);
    gmsh::model::geo::addCurveLoop({-63,-32,-53,-6},18);
    gmsh::model::geo::addCurveLoop({61,8,45,30},19);
    gmsh::model::geo::addCurveLoop({61,-7,53,-31},20);
    //левый
    gmsh::model::geo::addCurveLoop({62,33,50,-12},21);
    gmsh::model::geo::addCurveLoop({62,-32,40,11},22);
    gmsh::model::geo::addCurveLoop({2,-30,50,9},23);
    gmsh::model::geo::addCurveLoop({2,31,40,-10},24);
    //верхний левый
    gmsh::model::geo::addCurveLoop({4,12,51,-22},25);
    gmsh::model::geo::addCurveLoop({4,-11,46,25},26);
    gmsh::model::geo::addCurveLoop({60,-9,51,23},27);
    gmsh::model::geo::addCurveLoop({60,10,46,-24},28);
    //верхний правый
    gmsh::model::geo::addCurveLoop({3,22,39,5},29);
    gmsh::model::geo::addCurveLoop({3,-25,52,-6},30);
    gmsh::model::geo::addCurveLoop({1,-23,39,-8},31);
    gmsh::model::geo::addCurveLoop({1,24,52,7},32);
    //да да,это первый цикл, тут уж я сдался и решил оптимизировать
    for (int i = 0;i<32;++i)
    {
        gmsh::model::geo::addSurfaceFilling({i+1},i+1);
    }
        gmsh::model::geo::addSurfaceLoop({1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16},1);
        gmsh::model::geo::addSurfaceLoop({17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32},2);
        gmsh::model::geo::addVolume({2, 1}, 1);
    gmsh::model::geo::synchronize();
    gmsh::model::mesh::generate(3);
    gmsh::write("torus.msh");
    gmsh::write("torus.stl");
    std::set<std::string> args(argv, argv + argc);
    if(!args.count("-nopopup")) gmsh::fltk::run();
    gmsh::finalize();
    return 0;
}

