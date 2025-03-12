#ifndef WEBSOCKET_H
#define WEBSOCKET_H

#include <libwebsockets.h>

typedef void (*message_callback) (const char *message, size_t len, void *user_data);

struct ws_client {
    struct lws_context * context;
    struct lws *wsi;
    message_callback callback;
    void *user_data;
    int interrupted;
};

struct ws_client *ws_connect(const char *host, int port, message_callback cb, void *user_data);
void ws_send(struct ws_client *client, const char *message);
void ws_disconnect(struct ws_client *client);
void *ws_list(void *arg);

#endif