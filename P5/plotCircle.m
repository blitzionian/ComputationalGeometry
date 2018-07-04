function [] = plotCircle(x, y, r, setAxis)
    if setAxis
        axis([(x - r - 10) (x + r + 10) (y - r - 10) (y + r + 10)]);
    end

    ang=0:0.01:2*pi; 
    xp=r*cos(ang);
    yp=r*sin(ang);
    plot(x+xp,y+yp);
end
