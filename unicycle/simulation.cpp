#include <iostream>
#include <cmath>

class Robot{
    public:
        double x;
        double y;
        double theta;

    Robot(double x, double y, double theta){
        this->x = x;
        this->y = y;
        this->theta = theta;
    }
};


int main(){
    
    double v = 1; //velocity at which the robot moves in [m/s]
    double omega = 0.5; //Angular velocity of the robot in [rad/s]
    double dt = 0.1; //time step in seconds

    Robot robot1(0, 0, 0);

    double x1, y1, theta1; //The robot's new position parameters after each time step(dt)

    for(int i=0; i<50; i++){

        double x_rate_dt= v * cos(robot1.theta) * dt;
        double y_rate_dt = v * sin(robot1.theta) * dt;

        x1 = robot1.x + x_rate_dt;
        y1 = robot1.y + y_rate_dt;
        theta1 = robot1.theta + (omega * dt);

        std:: cout << "Step " << i << ":: x= " << x1 
                   <<" || y= " << y1 
                   << " || theta= " << theta1 << std::endl;

        //Updating the psoition parameters
        robot1.x = x1; 
        robot1.y = y1;
        robot1.theta = theta1;
    }

    return 0;
}