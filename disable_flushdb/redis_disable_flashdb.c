#include <redis.h>

static void* flushdb;

extern int redis_lib_init(redisClient *c) {
    flushdb = dictFetchValue(server.commands, sdsnew("FLUSHDB"));
    if (!flushdb) return 1;
    dictDeleteNoFree(server.commands, sdsnew("FLUSHDB"));
    return 0;
}

extern void redis_lib_depose(redisClient *c) {
    dictAdd(server.commands, sdsnew("FLUSHDB"), flushdb);
    return;
}
