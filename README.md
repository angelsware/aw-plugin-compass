# aw-plugin-compass

Compass plugin for Angels' Ware rendering engine.

### Getting Started

Add the **plugins** section to the **config.yaml** file of your project.

```
...

plugins:
-	repo: https://github.com/angelsware/aw-plugin-compass.git
```

```
Compass::ISensor* compassSensor = Compass::CSensorFactory::create();
compassSensor->onCreate();
compassSensor->addListener(this);

```
