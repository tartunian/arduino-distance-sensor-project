function y = filterSignalRealTime(x,next_x_chunk)
    persistent h;
    %h = 2*[0.2490 0.0039 0.0039 0.0039 0.2490];
    h=[0.0144 0.0304 0.0724 0.1245 0.1668 0.1830 0.1668 0.1245 0.0724 0.0304 0.0144];
    Lsignal = length(x);
    Lfilter = length(h);
    y = [];
    h_hat = h(end:-1:1);
    x_hat = [zeros(1,Lfilter-1) x zeros(1,Lfilter-1)];
%     for i=1:(Lsignal+Lfilter-1)
        x_hat_hat = [x next_x_chunk];
        y=[y sum(h_hat.*x_hat_hat)];
        %y=[y sum(h_hat.*x_hat(i:Lfilter+i-1))];
%     end
end