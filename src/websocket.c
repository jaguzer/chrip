#include "websocket.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

static int callback(struct lws *swi, enum lws_callback_reasons reason, void *user, void *in, size_t len) {
    struct ws_client *client = (struct ws_client *)user;

    switch (reason) {
        case LWS_CALLBACK_CLIENT_ESTABLISHED:
            printf("WebSocket connected\n");
            break;
        case LWS_CALLBACK_CLIENT_RECEIVE:
            if (client->callback) client->callback((char *)in, len, client->user_data);
    }
})