function [] = calculateAndPrintInCircle(filename, setAxis)
    [mx, my, mr, xs, ys] = calculateInCircle(filename);

    hold on;
    plot(xs, ys);
    plotCircle(mx, my, mr, setAxis);
    hold off;
end

