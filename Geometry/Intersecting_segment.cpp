//两线段是否相交
int inclu(Point const &p1,Point const &p2,Point const &p3){
    return sgn(Dist(p2,p1)+Dist(p3,p1)-Dist(p2,p3))==0;//利用距离判断p1是否在线段p2p3上
}
int cccc(Point p1,Point p2,Point p3,Point p4){
    Line l1={p1,p2-p1};
    Line l2={p3,p4-p3};
    if(inclu(p1,p3,p4)||inclu(p2,p3,p4)||inclu(p3,p1,p2)||inclu(p4,p1,p2))return true;//先判断端点是否在另一条线段上
    if(sgn(Outer(l1.v,l2.v))!=0){//不平行
        Point mmp=Cross(l1,l2);//求出交点
        return inclu(mmp,p1,p2);
    }else return false;//平行，且端点不在另一条线段上
}
