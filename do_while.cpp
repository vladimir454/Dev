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
    
//    int i, n, count = 0; //if is for count=0; count<n; count++
    int sum, num;
    
    sum=0;
    
    do { //va a ejecutar el do
        cout<<"dame un numero"<<endl;
        cin>>num;
        sum=sum+num; //aqui esta ejecutando la suma del numero
        
    } while (num!=0); //mientras numero no sea cero
    
    cout<<"el resultado es: "<<sum<<endl;
    
   
    
    return 0;
}
