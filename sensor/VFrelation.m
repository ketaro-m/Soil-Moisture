data = readmatrix('sensor.xlsx','Range','C4:D15'); %import data
%%
x = linspace(0,99,100);
y = 3115.2*exp(-0.026*x);
figure;
plot(x,y)
hold on
scatter(data(:,1),data(:,2),'filled','r')
xlim([0,100])
ylim([0,3200])
grid on
xlabel('Soil moisture [%]')
ylabel('Sensor output')
legend({'$y = 3115.2\exp (-0.026x)$','Real Data'},'Location','northeast','Interpreter','latex')
title('Sensor property')
%%
%inverse function
y = linspace(0,3199,3200);
x = log(y/3115.2)/(-0.026);
figure;
plot(y,x)
hold on
scatter(data(:,2),data(:,1),'filled','r')
xlim([0,3200])
ylim([0,100])
grid on
xlabel('Sensor output')
ylabel('Soil moisture [%]')
legend({'$x = -\frac{1}{0.026}\log \biggl(\frac{y}{3115.2}\bigg)$','Real Data'},'Location','northeast','Interpreter','latex')
title('Sensor property')
%%
%subplot
x = linspace(0,99,100);
y = 3115.2*exp(-0.026*x);
figure;
subplot(2,1,1)
plot(x,y)
hold on
scatter(data(:,1),data(:,2),'filled','r')
xlim([0,100])
ylim([0,3200])
grid on
xlabel('Soil moisture [%]')
ylabel('Sensor output')
legend({'$y = 3115.2\exp (-0.026x)$','Real Data'},'Location','northeast','Interpreter','latex')
title('Sensor property')
%inverse function
y = linspace(0,3199,3200);
x = log(y/3115.2)/(-0.026);
subplot(2,1,2)
plot(y,x)
hold on
scatter(data(:,2),data(:,1),'filled','r')
xlim([0,3200])
ylim([0,100])
grid on
xlabel('Sensor output')
ylabel('Soil moisture [%]')
yticks([0,20,40,60,80,100])
legend({'$x = -\frac{1}{0.026}\log \biggl(\frac{y}{3115.2}\bigg)$','Real Data'},'Location','northeast','Interpreter','latex')
title('Sensor property')