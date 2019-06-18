#include "base.h"

bool Base::IsBoom(const Base &base)const{
bool isok=true;
if(m_bDisappear==true||base.m_bDisappear==true||base.m_rectSphere.left()>m_rectSphere.right()
||base.m_rectSphere.right()<m_rectSphere.left()||base.m_rectSphere.top()>m_rectSphere.bottom()||base.m_rectSphere.bottom()<m_rectSphere.top())
isok=false;

return isok;
}

void Base::downlife(float attack){
life=life-attack;
if(life<0)
{m_bDisappear=true;
    life=0;}
}
