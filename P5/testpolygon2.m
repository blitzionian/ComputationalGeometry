Coords = dlmread('testpolygon2.txt');
% disp(Coords);

coordsSize = size(Coords);
A=[];
b=[];

lastIndx = coordsSize(1);
for line = 1:lastIndx -1
   p1 = Coords(line, 1);
   p2 = Coords(line, 2);
   
   q1 = Coords(line + 1, 1);
   q2 = Coords(line + 1, 2);

   lineLength = sqrt((p1-q1)^2 + (p2 - q2)^2);
   
   m1 = (p2 - q2) / lineLength;
   m2 = (q1 - p1) / lineLength;
   A = [A; m1 m2 -1];
   
   result = (p2 * q1 + p1 * q2) / lineLength;
   b = [b; result];
end

x = A\b;

out = sprintf('X: %f', abs(x(1)));
disp(out);
out = sprintf('Y: %f', abs(x(2)));
disp(out);

out = sprintf('Radius: %f', abs(x(3)));
disp(out);