function [mx, my, mr, polygonXs, polygonYs] = calculateInCircle(filename)
    Coords = dlmread(filename);

    coordsSize = size(Coords);
    A=[];
    b=[];

    lastIndx = coordsSize(1);
    polygonXs = [];
    polygonYs = [];
    
    sum = 0;

    for line = 1:lastIndx -1
       p1 = Coords(line, 1);
       p2 = Coords(line, 2);

       q1 = Coords(line + 1, 1);
       q2 = Coords(line + 1, 2);

       polygonXs = [polygonXs, p1];
       polygonYs = [polygonYs, p2];

       lineLength = sqrt((p1-q1)^2 + (p2 - q2)^2);

       m1 = (p2 - q2) / lineLength;
       m2 = (q1 - p1) / lineLength;
       A = [A; -m1 -m2 1];

       result = (-p2 * q1 + p1 * q2) / lineLength;
       b = [b; -result];
       sum = sum + result;
    end
    
%   if(sum < 0)
%       b = -b;
%   end

    polygonXs = [polygonXs, q1];
    polygonYs = [polygonYs, q2];

    f = [0 0 -1];
    x = linprog(f, A, b);
    
    mx = abs(x(1));
    my = abs(x(2));
    mr = abs(x(3));

    out = sprintf('X: %f', mx);
    disp(out);
    
    out = sprintf('Y: %f', my);
    disp(out);

    out = sprintf('Radius: %f', mr);
    disp(out);
end
