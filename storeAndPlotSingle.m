function storeAndPlotSingle(data,datastore)
    [laser,sonic,timestamp,success]=extractReadings(data);
    if(success)
        datastore.addReading(laser,sonic,timestamp);
        plot(datastore.totalreadings,laser,'rx');
        hold on;
        plot(datastore.totalreadings,sonic,'bo');
    end
end