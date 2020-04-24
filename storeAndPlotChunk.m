function storeAndPlotChunk(data,datastore)

    chunk_length = 30;
    overlap = 10;

    laser_buffer =[];
    sonic_buffer =[];
    timestamp_buffer = [];

    [laser,sonic,timestamp]=extractReadings(data);
    laser_buffer = [laser_buffer; laser];
    sonic_buffer = [sonic_buffer; sonic];
    timestamp_buffer = [timestamp_buffer; timestamp];
    datastore.addReading(laser,sonic,timestamp);

    if(datastore.totalreadings~=0&&mod(datastore.totalreadings,chunk_length)==0)
        laser_chunk = [];
        sonic_chunk = [];
        if(datastore.totalreadings==chunk_length)
            laser_chunk = [zeros(overlap,1); datastore.getColumnMatrix(1,chunk_length)];
            sonic_chunk = [zeros(overlap,1); datastore.getColumnMatrix(2,chunk_length)];
        else
            laser_chunk = datastore.getColumnMatrix(1,chunk_length+overlap);
            sonic_chunk = datastore.getColumnMatrix(2,chunk_length+overlap);
        end
        laser_filtered = filterSignalChunk(laser_chunk);
        laser_filtered = laser_filtered(overlap+1:end-overlap);

        sonic_filtered = filterSignalChunk(sonic_chunk);
        sonic_filtered = sonic_filtered(overlap+1:end-overlap);

        chunk_range = datastore.totalreadings-overlap-chunk_length+1:datastore.totalreadings;
        filtered_range = chunk_range(overlap+1:end);
        
        plot(filtered_range,laser_filtered,'r');
        hold on;
        plot(filtered_range,sonic_filtered,'b');
    end

end