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
    
    int n,sum;
    
    sum=0;
    cout<<"escribir un numero"<<endl;
    
    while (sum<100) {
        if (sum>0) {
            cout<<"falta completar siga escribiendo"<<endl;
        }
        cin>>n;
        sum=sum+n;
        cout<<"suma total es:\n"<<sum<<endl;
        
    }
    cout<<"la suma total es"<<sum<<endl;
    if (sum>=100)
    {
        cout<<"you have done"<<endl;
    }
    return 0;

}
 -----------result --------------------------------
 escribir un numero
100
suma total es:
100
la suma total es100
you have done
Program ended with exit code: 0
