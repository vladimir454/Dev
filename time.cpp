//
//  main.cpp
//  moduls
//
//  Created by Vlc on 17/6/16.
//  Copyright © 2017年 Vlc. All rights reserved.
//

#include <iostream>
#include<unistd.h>
using namespace std;

int main(int argc, const char * argv[]) {
    // insert code here...
    
    double s,m,h;
    cout<<"white a time"<<endl;
    cin>>h>>m>>s;
    
    while (h<24) {
        h++;
        for (m=0; m<60; m++){
            for (s=0; s<60; s++) {
          
                cout<<"now is: "<<h<<":"<<m<<":"<<s<<"\n"<<endl;
                usleep(1000*10);
            }
        }
    }
    //modified now
    return 0;

}
