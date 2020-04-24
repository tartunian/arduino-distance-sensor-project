function handleNewDataRealTime(src,datainfo,datastore)
    if(datastore.totalreadings>0&&mod(datastore.totalreadings,20)==0)
        recent = datastore.getColumnMatrix(4,20);
        sample_rate = 20*1000/double(recent(end)-recent(1));
        "Sample Rate: " + string(sample_rate) + "Hz"
    end
    chunk_length = 30;
    overlap = 10;
    data = readline(src);
    [laser,sonic,timestamp,success]=extractReadings(data);
    if(success)
        datastore.addReading(laser,sonic,timestamp);
        plot(datastore.totalreadings,laser,'rx');
        hold on;
        plot(datastore.totalreadings,sonic,'rx');

    end
end