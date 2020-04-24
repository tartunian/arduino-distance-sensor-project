classdef DataStore < handle
    properties
        data
        sessionname
        controldistance
        totalreadings
    end
    methods
        function h = DataStore()
            h.data = [];
            h.sessionname = 'trial-'+string(fix(now*10000));
            h.controldistance = 0;
            h.totalreadings = 0;
        end
        function addReading(datastore,laser,sonic,timestamp)
            datastore.data = [datastore.data; {laser sonic datastore.controldistance timestamp}];
            datastore.totalreadings = datastore.totalreadings + 1;
        end
        function c = getColumnMatrix(datastore,column,numreadings)
%             "Return start: " + string(datastore.totalreadings-numreadings+1)
%             "Return end  : " + string(datastore.totalreadings)
            c = cell2mat(datastore.data(datastore.totalreadings-numreadings+1:datastore.totalreadings,column));
        end
        function clear(datastore)
            datastore.data = [];
            datastore.totalreadings = 0;
        end
        function reset(datastore)
            datastore.clear();
            datastore.controldistance = 0;
            datastore.sessionname = 'trial-'+string(fix(now*10000));
        end
    end
end