# Raytracing

![](output.png?raw=True)
Creepy Mickey Mouse snowman with broken arm.<br> <br>

# Installation

Clone the repository and run the main.cpp file.

# Change Settings

Before you run the main.cpp file, you can change the settings with editing the settings.json file. <br>

### Parameters:

**width:** width of the final image.<br>
**height:** height of the final image.<br>
**camera_pos_x:** x coordinate shift of the camera. This value will be added to the center of the width.<br>
**camera_pos_y:** y coordinate shift of the camera.  This value will be added to the center of the height.<br>
**background_color:** color of the background in hex format.<br>
**image_folder:** Optional path to a directory where the generated image should be saved at. Use double \\\\ to enter a
path, for example "C:\\\\Documents".<br>
**light_sources:** list of the light sources (only one light source supported yet). <br>
&emsp; **pos_x:** x coordinate of the light source. <br>
&emsp; **pos_y:** y coordinate of the light source. <br>
&emsp; **pos_z:** z coordinate of the light source. <br>
&emsp; **intensity:** intensity of the light source. <br>
**spheres:** list of the light sources (only one light source supported yet) <br>
&emsp; **pos_x:** x coordinate of the sphere. <br>
&emsp; **pos_y:** y coordinate of the sphere. <br>
&emsp; **pos_z:** z coordinate of the sphere. <br>
&emsp; **radius:** radius of the sphere. <br>
&emsp; **color:** color of the sphere in hex format. <br>

### Top generate the image shown above, use the following settings.json file:

```{
  "width": 1600,
  "height": 800,
  "camera_pos_x": 0,
  "camera_pos_y": 0,
  "background_color": "#2874b2",
  "image_folder": "",
  "light_sources": [
    {
      "pos_x": 800,
      "pos_y": 300,
      "pos_z": 0,
      "intensity": 0.8
    }
  ],
  "spheres": [
    {
      "pos_x": 800,
      "pos_y": 450,
      "pos_z": 300,
      "radius": 200,
      "color": "#804000"
    },
    {
      "pos_x": 670,
      "pos_y": 250,
      "pos_z": 300,
      "radius": 100,
      "color": "#804000"
    },
    {
      "pos_x": 930,
      "pos_y": 250,
      "pos_z": 300,
      "radius": 100,
      "color": "#804000"
    },
    {
      "pos_x": 750,
      "pos_y": 350,
      "pos_z": 100,
      "radius": 30,
      "color": "#FFFFFF"
    },
    {
      "pos_x": 850,
      "pos_y": 350,
      "pos_z": 100,
      "radius": 30,
      "color": "#FFFFFF"
    },
    {
      "pos_x": 800,
      "pos_y": 410,
      "pos_z": 100,
      "radius": 30,
      "color": "#FE0202"
    },
    {
      "pos_x": 715,
      "pos_y": 470,
      "pos_z": 100,
      "radius": 30,
      "color": "#b1b0ae"
    },
    {
      "pos_x": 755,
      "pos_y": 500,
      "pos_z": 100,
      "radius": 30,
      "color": "#b1b0ae"
    },
    {
      "pos_x": 810,
      "pos_y": 500,
      "pos_z": 100,
      "radius": 30,
      "color": "#b1b0ae"
    },
    {
      "pos_x": 865,
      "pos_y": 500,
      "pos_z": 100,
      "radius": 30,
      "color": "#b1b0ae"
    },
    {
      "pos_x": 905,
      "pos_y": 470,
      "pos_z": 100,
      "radius": 30,
      "color": "#b1b0ae"
    },
    {
      "pos_x": 800,
      "pos_y": 800,
      "pos_z": 300,
      "radius": 300,
      "color": "#804000"
    },
    {
      "pos_x": 500,
      "pos_y": 650,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 450,
      "pos_y": 590,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 400,
      "pos_y": 530,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 350,
      "pos_y": 590,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 1100,
      "pos_y": 650,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 1150,
      "pos_y": 590,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 1200,
      "pos_y": 530,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 1250,
      "pos_y": 470,
      "pos_z": 300,
      "radius": 40,
      "color": "#804000"
    },
    {
      "pos_x": 1500,
      "pos_y": 100,
      "pos_z": 200,
      "radius": 200,
      "color": "#fce903"
    },
    {
      "pos_x": 740,
      "pos_y": 340,
      "pos_z": 50,
      "radius": 10,
      "color": "#000000"
    },
    {
      "pos_x": 860,
      "pos_y": 360,
      "pos_z": 50,
      "radius": 10,
      "color": "#000000"
    }
  ]
}
```