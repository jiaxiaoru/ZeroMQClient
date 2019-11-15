//
//  main.c
//  ZeroMQClient
//
//  Created by Judith on 2019/11/13.
//  Copyright © 2019 Judith. All rights reserved.
//

#include <stdio.h>
#include "zmq.h"

int main(int argc, const char * argv[]) {
    void *context = zmq_ctx_new();
    void *requester = zmq_socket(context, ZMQ_REQ);
    zmq_connect(requester, "tcp://localhost:5555");
    for (int i = 0; i < 10; i++) {
        printf("client start request %d \n",i);
        zmq_send(requester, "request connect", 16, 0);
        char buffer[10];
        zmq_recv(requester, buffer, 10, 0);
        printf("client received message %s \n",buffer);
    }
    return 0;
}
