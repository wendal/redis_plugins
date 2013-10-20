#include <redis.h>

static void* flashdb;

void nop(redisClient *c){
    addReply(c, shared.ok);
}

extern int redis_lib_init(redisClient *c) {
    if (flashdb) return 1;
    printf("%d", server.commands->iterators);
    flashdb = dictFetchValue(server.commands, sdsnew("FLUSHDB"));
    dictDeleteNoFree(server.commands, sdsnew("FLUSHDB"));
    return 0;
}

extern void redis_lib_depose(redisClient *c) {
    dictAdd(server.commands, sdsnew("FLUSHDB"), flashdb);
    return;
}
