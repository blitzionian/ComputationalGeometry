Coords = dlmread('testpolygon3.txt');

coordsSize = size(Coords);
A=[];
b=[];

lastIndx = coordsSize(1);
xs = [];
ys = [];

for line = 1:lastIndx -1
   p1 = Coords(line, 1);
   p2 = Coords(line, 2);
   
   q1 = Coords(line + 1, 1);
   q2 = Coords(line + 1, 2);
   
   xs = [xs, p1];
   ys = [ys, p2];

   lineLength = sqrt((p1-q1)^2 + (p2 - q2)^2);
   
   m1 = (p2 - q2) / lineLength;
   m2 = (q1 - p1) / lineLength;
   A = [A; -m1 -m2 1];
   
   result = (-p2 * q1 + p1 * q2) / lineLength;
   b = [b; -result];
end

xs = [xs, q1];
ys = [ys, q2];

hold on;
plot(xs, ys);
circle(abs(x(1)), abs(x(2)), abs(x(3)));
hold off;

f = [0 0 -1];
x = linprog(f, A, b);

out = sprintf('X: %f', abs(x(1)));
disp(out);
out = sprintf('Y: %f', abs(x(2)));
disp(out);

out = sprintf('Radius: %f', abs(x(3)));
disp(out);


function circle(x,y,r)
    ang=0:0.01:2*pi; 
    xp=r*cos(ang);
    yp=r*sin(ang);
    plot(x+xp,y+yp);
end
