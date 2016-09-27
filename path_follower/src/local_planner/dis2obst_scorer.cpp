/// HEADER
#include <path_follower/local_planner/dis2obst_scorer.h>

double Dis2Obst_Scorer::DIS2O_ = 0.85;
double Dis2Obst_Scorer::factor_ = 1.0;
double Dis2Obst_Scorer::full_d = DIS2O_;

Dis2Obst_Scorer::Dis2Obst_Scorer():
    Scorer()
{

}

Dis2Obst_Scorer::~Dis2Obst_Scorer()
{

}

void Dis2Obst_Scorer::setLimit(double dis2o){
    DIS2O_ = dis2o;
}

void Dis2Obst_Scorer::setVDis(double dis){
    full_d = DIS2O_ + dis;
}

void Dis2Obst_Scorer::setFactor(double factor){
    factor_ = factor;
}

double Dis2Obst_Scorer::score(const LNode& point){
    sw.resume();
    double x = point.nop.x - point.x;
    double y = point.nop.y - point.y;
    double orio = std::atan2(y,x);
    x = point.npp.x - point.x;
    y = point.npp.y - point.y;
    double orip = std::atan2(y,x);
    double adiff1 = std::abs(MathHelper::AngleClamp(orio - point.orientation));
    double adiff2 = MathHelper::AngleClamp(orio - orip)/2.0;
    double exponent = factor_*(point.d2o - full_d);
    double score = std::sin(adiff1)*std::cos(adiff2)/std::exp(exponent);
    sw.stop();
    return score;
}
