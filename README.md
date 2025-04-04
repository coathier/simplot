# Simplot
C Header library to print C functions as ASCII graph.

Include the library like so.
```c
#define SIMPLOT_IMPLEMENTATION
#include "simplot.h"
```

Define a C function with with a `double` input and output.
```c
double f(double x) {
    if (x < -5)
        return cos(x);
    else if (x > 5)
        return (x - 7.5) / 2.5;
    else if (fabs(x) < 1)
        return 0;
    else
        return 1 / x;
}
```

Define the X range, you range is automatically calculated. Based on the lowest and highest value the function produces in the range. Also provide output symbol- width and height.
```c
int main(void) {
    uint16_t screen[2] = {120, 30};
    int16_t x_range[2] = {-10, 10};
    simplot(*f, screen, x_range);
    return 0;
}
```

Compile and run the exectuable, get the following output.
```
x: [-10 - 10], y: [-1, 1]
                     ###                                          #                                                     
                    #   ##                                                                                             #
                   #                                               #                                                  # 
                          #                                                                                          #  
                  #        #                                        #                                               #   
                 #                                                   #                                             #    
                            #                                         #                                           #     
                #                                                      ##                                        #      
                             #                                           ##                                     #       
               #                                                           ###                                 #        
                                                                              ####                            #         
                                                                                  ########                   #          
              #                                                                           #                 #           
                                                                                                           #            
             #                                         ###########                                       ##             
                                                                                                        #               
                                                                                                       #                
            #                 ##                                                                      #                 
                                #######                                                              #                  
           #                           ####                                                         #                   
                                           ###                                                     #                    
          #                                   ##                                                  #                     
                                                ##                                               #                      
         #                                        #                                             #                       
                                                   #                                           #                        
        #                                           #                                         #                         
                                                                                             #                          
#      #                                             #                                      #                           
 #    #                                                                                    #                            
  ####                                                #                                                                 
```
