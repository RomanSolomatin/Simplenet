	//
//  main.cpp
//  TestNetwork
// network code test and develop
//
//  Created by Jongwhan Lee on 29/08/2017.
//  Copyright © 2017 Jongwhan Lee. All rights reserved.
//

#include <iostream>
#include "Buffer.hpp"
#include "TcpServer.hpp"
#include "TcpClient.hpp"
#include "Queue.hpp"
using namespace Simplenet;
using namespace std;
bool g_exit = false;
void processTcpServer()
{
    TcpServer t;
    t.start(8084);
    cout<<"TcpServer Began"<<endl;
    while(!g_exit) {
        cout<<"q. exit"<<endl;
        string a;
        cin>>a;
        if ("q"==a) {
            g_exit = true;
            t.stop();
            break;
        }
    }
}
void processTcpClient()
{
    TcpClient t;
    t.start("localhost", 8084);
    cout<<"TcpClient Began"<<endl;
    while(!g_exit) {
        cout<<"q. exit"<<endl;
        string a;
        cin>>a;
        if ("q"==a) {
            g_exit = true;
            t.stop();
            break;
        }
    }
}
void serverMain()
{
    while(!g_exit) {
        cout<<"1. run tcp server"<<endl;
        cout<<"2. run tcp client"<<endl;
        cout<<"q. exit"<<endl;
        string a;
        cin>>a;
        
        if ("1"==a) {
            processTcpServer();
        }
        else if ("2"==a) {
            processTcpClient();
        }
        if ("q"==a) {
            break;
        }
    }
}

void testQueue();
int main(int argc, const char * argv[])
{
    testQueue();
    return 0;
}
