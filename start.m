function start(src,store)
    flush(src);
    store.clear();
    configureCallback(src,"terminator",@(src,datainfo,datastore)handleNewData(src,datainfo,store));
end