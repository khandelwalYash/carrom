float str_x;
float str_y;

class strkr
{
public:
    float x;
    float y;
    float speed_factor;
    float vel_x;
    float vel_y;
strkr()
{
	speed_factor = 1;

}
void moveRight()
{
	x+=0.05;
}

void moveLeft()
{
	x-=0.05;
}

void  incTheta(float str_theta)
{
	//float 
	str_theta +=3.14159*1/180;
	str_x = 0.6*cos(str_theta);
	str_y = 0.6*sin(str_theta);	

}

void  decTheta(float str_theta)
{
	//float 
	str_theta -=3.14159*1/180;
	str_x = 0.6*cos(str_theta);
	str_y = 0.6*sin(str_theta);	

}

void incSpeed()
{
	if(speed_factor<10)
	speed_factor+=1;

}
void decSpeed()
{
	if(speed_factor>1)
	speed_factor-=1;
}
};