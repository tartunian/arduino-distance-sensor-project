function showSampleRate(datastore)
    if(mod(datastore.totalreadings,20)==0&&datastore.totalreadings>0)
        recent = datastore.getColumnMatrix(4,20);
        freq = 20*1000/double(recent(end)-recent(1));
        "Sample Rate: " + string(freq) + "Hz"
    else
end