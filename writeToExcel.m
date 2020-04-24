function writeToExcel(datastore)
    datatable = table(datastore.data);
    filename = 'distance_sensor_readings.xlsx';
%     if(exist(filename,'file'))
%         [~,sheets]=xlsfinfo(filename);
%         sheetName = 'trial-'+string(length(sheets)+1);
%     else
%         sheetName = 'trial-1';
%     end
    sheetName=datastore.sessionname;
    writetable(datatable,filename,'Sheet',sheetName,'Range','A1');
end