function handleNewData(src,datainfo,datastore)
    %showSampleRate(datastore);
    data = readline(src);
    storeAndPlotChunk(data,datastore);
end