function handleNewData(src,datainfo,datastore)
    %showSampleRate(datastore);
    data = readline(src);
    storeAndPlotSingle(data,datastore);
end