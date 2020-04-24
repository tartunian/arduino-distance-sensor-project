function [laser,sonic,timestamp,success] = extractReadings(data)
    readings = split(data,' ');
    if(length(readings)==3)
        laser = double(str2double(readings(1)));
        sonic = double(str2double(readings(2)));
        timestamp = uint32(str2double(readings(3)));
        success = true;
    else
        laser = double(-1);
        sonic = double(-1);
        timestamp = uint32(-1);
        success = false;
    end
end