#include <redis.h>

extern int redis_lib_init(redisClient *c) {
    //addReply(c,shared.ok);
    //dictPrintStats(server.commands);
    return 0;
}

extern void redis_lib_depose(redisClient *c) {
    return;
}
