function [filterObject, filteredData, filteredMean, filteredStd, settlingTime] = lpf_filter(type,passFreq, stopFreq, passRipple, stopAtt, dataset, Fs)
%UNTITLED Summary of this function goes here
%   Detailed explanation goes here
t = linspace(1, 8192, 8192);
lpf = designfilt('lowpassiir', ...
                  'PassbandFrequency', passFreq, ...
                  'StopbandFrequency', stopFreq, ...
                  'PassbandRipple', passRipple, ...
                  'StopbandAttenuation', stopAtt,...
                  'DesignMethod', type, ...
                  'MatchExactly', 'stopband',...
                  'SampleRate', Fs);

data_lpf = filter(lpf, dataset);

settlingTime = 0;
counter = 0;
flag = 0;
for i = 1:8192
    if data_lpf(i) > 0.995*mean(dataset) && data_lpf(i) < 1.005*mean(dataset) && flag == 1
            counter = counter + 1;
    elseif data_lpf(i) > 0.995*mean(dataset) && data_lpf(i) < 1.005*mean(dataset) && flag == 0
        settlingTime = i;
        counter = 1;
        flag = 1;
    else
        settlingTime = 0;
        counter = 0;
        flag = 0;
    end
    if counter == 1000
        break
    end
end
if settlingTime == 0
    settlingTime = 3000;
end
filteredMean = mean(data_lpf(settlingTime:8192));
filteredStd = std(data_lpf(settlingTime:8192));
filterObject = lpf;
filteredData = data_lpf;
end