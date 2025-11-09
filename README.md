[![openpilot on the comma 3X](https://i.imgur.com/Zwv9SaN.png)](https://comma.ai/shop/comma-3x)

What is openpilot?
------

[openpilot](http://github.com/commaai/openpilot) is an open source driver assistance system. Currently, openpilot performs the functions of Adaptive Cruise Control (ACC), Automated Lane Centering (ALC), Forward Collision Warning (FCW), and Lane Departure Warning (LDW) for a growing variety of [supported car makes, models, and model years](docs/CARS.md). In addition, while openpilot is engaged, a camera-based Driver Monitoring (DM) feature alerts distracted and asleep drivers. See more about [the vehicle integration](docs/INTEGRATION.md) and [limitations](docs/LIMITATIONS.md).

<table>
  <tr>
    <td><a href="https://youtu.be/NmBfgOanCyk" title="Video By Greer Viau"><img src="https://github.com/commaai/openpilot/assets/8762862/2f7112ae-f748-4f39-b617-fabd689c3772"></a></td>
    <td><a href="https://youtu.be/VHKyqZ7t8Gw" title="Video By Logan LeGrand"><img src="https://github.com/commaai/openpilot/assets/8762862/92351544-2833-40d7-9e0b-7ef7ae37ec4c"></a></td>
    <td><a href="https://youtu.be/SUIZYzxtMQs" title="A drive to Taco Bell"><img src="https://github.com/commaai/openpilot/assets/8762862/05ceefc5-2628-439c-a9b2-89ce77dc6f63"></a></td>
  </tr>
</table>

What is FrogPilot? 🐸
------

FrogPilot is a fully open-sourced fork of openpilot, featuring clear and concise commits striving to be a resource for the openpilot developer community. It thrives on contributions from both users and developers, focusing on a collaborative, community-led approach to deliver an advanced openpilot experience for everyone!

------
FrogPilot was last updated on:

**April 12th, 2025**

Features
------

FrogPilot offers a wide range of customizable features that are easily toggled on or off to suit your preferences. Whether you want a completely stock openpilot experience, or want to add some fun and personal touches, FrogPilot has you covered! Some of the features include:

------
⚡ **Advanced Customizations:**

  - "Alert Volume Controller" to set the volume level for each of of openpilot's sounds
  - Customize the following distance and jerk values for each personality profile
  - Fine tune your car's "Steer Ratio" to perfect your lateral control
  - Increase the distance when stopped behind lead vehicles
  - Increase the max set speed by a custom interval (i.e. 2, 3, 4, 5, 6, etc. instead of just 1)
  - Select between past, present, and future openpilot driving models
------
🎨 **Custom Themes:**

  - 🐸 Frog theme (with a bonus 🐐 sound effect)
  - <img src="https://images.emojiterra.com/google/noto-emoji/unicode-15/color/512px/1f1f7-1f1fa.png" width="15" height="12"> Russia / Joseph Stalin theme
  - 🔌 Tesla theme
  - Holiday themes! Minor holidays last a day, while major holidays (Easter, Halloween, Thanksgiving, Christmas) last a week
  - Random events triggered by specific actions while driving with openpilot

  - 📢 Want to add a theme? Request one in the "feature-request" channel in the FrogPilot Discord!
------
🚀 **Conditional Experimental Mode:**

  - Auto-activates "Experimental Mode" under several conditions, including:
    - Approaching intersections and turns while using navigation
    - Approaching slower vehicles to take advantage of "Experimental Mode"'s smoother braking
    - Curve and stop light/stop sign detection
    - Driving below a set speed
    - Turn signal activation below 55mph for turn assistance
------
📊 **Developer UI:**

  - Display various driving logics such as the distance, speed, and the desired following distance to your lead vehicle
  - Lane measuring of the adjacent lanes for lane detection
  - Tap the "VEHICLE ONLINE"/"CPU"/"GPU" gauge to toggle between CPU and GPU monitoring
  - Tap the "CONNECT ONLINE"/"MEMORY"/"LEFT"/"USED" gauge to toggle between RAM and storage monitoring
------
🛠 **Device Management:**

  - Adjustable screen brightness for both onroad and offroad states
  - Adjustable screen timeout times for both onroad and offroad states
  - Backup and restore previous versions of FrogPilot
  - Backup and restore previous versions of toggle configurations
  - Battery level threshold to automatically shut the device down after you car's battery falls below a set voltage limit when offroad
  - Delete stored driving data for increased privacy/space via the "Device" panel
  - Device can operate offline indefinitely
  - Disable logging and/or uploading
  - Disable uploads while onroad to help reduce data usage
  - Flash the Panda within the "Device" menu
  - "Standby Mode" that wakes the screen up between engagement states or when important alerts are triggered
  - Timer to automatically shut down after going offroad
------
🚖 **Lateral Adjustments:**

  - Activate lateral control by simply pressing the "Cruise Control" button
  - Force comma's auto tuning for unsupported vehicles
  - Lateral control won't disengage on gas or brake
  - Nudgeless lane changes with lane detection to prevent driving into curbs or going offroad
  - Pause lateral control when below a set speed
  - Pause lateral control when pressing the brake
  - Pause lateral control when turn signals are active
  - Precise turns by using turn desires when below the minimum lane change speed
  - [Twilsonco's NNFF](https://github.com/twilsonco/openpilot) for smoother steering control
------
🚘 **Longitudinal Adjustments:**

  - Aggressive acceleration when following a lead vehicle from a stop
  - "Map Turn Speed Controller" to slow down for curves based on stored map data
    - With an additional toggle to fine tune the speed aggressiveness
  - Smoother braking behind slower leads
  - "Speed Limit Controller" to adjust your speed to the posted speed limit
    - With additional toggles to set offsets for "0-34 mph", "35-54 mph", "55-64 mph", and "65-99 mph"
  - "Sport" and "Eco" acceleration and deceleration profiles
  - "Traffic Mode" tailored towards driving in traffic
  - Tweak the lead detection threshold to detect leads sooner for smoother braking on stopped/slower vehicles
  - "Vision Turn Speed Controller" for smoother handling of curves
    - With additional toggles to fine tune the speed aggressiveness and curve detection sensitivity
------
🗺️ **Navigation:**

  - 3D buildings
  - Custom map styles
  - Full screen map that takes up the entire screen for a more expansive map view
  - iOS shortcuts to quickly set navigation destinations
  - Navigate on openpilot without a comma prime subscription
  - Offline maps
  - "Open Street Maps" integration for speed limit control and road name view
------
🎮 **Onroad UI:**

  - Compass that rotates according to the direction you're driving
  - FPS counter in the screen's border
  - Hide various UI elements on the screen for a cleaner UI
  - Pedals on the onroad UI indicate when the gas/brake pedals are being used
  - Road UI Customizations:
    - Acceleration path to show the model's desired acceleration/deceleration
    - Blind spot path when a vehicle is detected in your blind spot
    - Increase/decrease the lane line, path, and road edge widths
    - Path edge colors based on specific driving statuses:
      - 🔵 Blue - Navigation active
      - 🟦 Light Blue - "Always On Lateral" active
      - 🟢 Green - Default
      - 🟠 Orange - "Experimental Mode" active
      - 🔴 Red - "Traffic Mode" active
      - 🟡 Yellow - "Conditional Experimental Mode" overridden
    - "Unlimited" road UI that extends out as far as the model can see
  - Sidebar retains it's previous position between reboots/ignition cycles
  - Steering wheel icons
    - 📢 Request your own steering wheel icon in the "feature-request" channel!
  - Steering wheel in the onroad UI rotates alongside your physical steering wheel
------
🚙 **Vehicle Specific Additions:**

  - Automatic/manual fingerprint selection to force a selected fingerprint
  - Custom longitudinal tunings for GM EVs and trucks for smoother gas and brake control
  - Custom longitudinal tunings for Toyota/Lexus for smoother gas and brake control
  - Disable openpilot longitudinal control to use your car's stock cruise control
  - GM Volt support
  - Honda Clarity support
  - Increased torque for the Subaru Crosstrek
  - Lock doors automatically when in the drive gear for Toyota/Lexus and unlock when in park
  - openpilot longitudinal control for GM vehicles without ACC
  - Pedal interceptor support for GM vehicles
  - "Stop and Go" hack for Toyota's without stop and go functionality
  - ZSS support for the Toyota Prius and Sienna
------
🚦 **Quality of Life Features:**

  - Automatic updates for a completely "set and forget" experience
  - Camera view selection
  - Custom alerts for green lights, vehicles in blindspot, lead departing, and the current speed limit changing
  - Display the driver camera when in reverse
  - Driving statistics to show how many hours and miles you've driven on the home screen
  - Fleet Manager to easily access your driving data and screen recordings
  - Numerical temperature gauge
  - Retain tethering status between reboots
  - Screenrecorder
  - Toggle "Experimental Mode" via the "Lane Departure Alert" button, holding down the "Distance" button for 0.5+ seconds, or by double tapping the screen

How to Install
------

Easiest way to install FrogPilot is via this URL at the installation screen:

```
frogpilot.download
```

DO NOT install the "FrogPilot-Development" branch. I'm constantly breaking things on there, so unless you don't want to use openpilot, NEVER install it!

![](https://i.imgur.com/swr0kqJ.png)

Bug reports / Feature Requests
------

If you encounter any issues or bugs while using FrogPilot, or if you have any suggestions for new features or improvements, please don't hesitate to post about it on the Discord! I'm always looking for ways to improve the fork and provide a better experience for everyone!

To report a bug or request a new feature, make a post in the #bug-reports or #feature-requests channel respectively on the FrogPilot Discord. Please provide as much detail as possible about the issue you're experiencing or the feature you'd like to see added. Photos, videos, log files, or other relevant information are very helpful!

I will do my best to respond to bug reports and feature requests in a timely manner, but please understand that I may not be able to address every request immediately. Your feedback and suggestions are valuable, and I appreciate your help in making FrogPilot the best it can be!

Discord
------

[Join the FrogPilot Community Discord!](https://discord.gg/frogpilot)

Credits
------

* [AlexandreSato](https://github.com/AlexandreSato)
* [Crwusiz](https://github.com/crwusiz)
* [DragonPilot](https://github.com/dragonpilot-community)
* [ErichMoraga](https://github.com/ErichMoraga)
* [Garrettpall](https://github.com/garrettpall)
* [Mike8643](https://github.com/mike8643)
* [Neokii](https://github.com/Neokii)
* [OPGM](https://github.com/opgm)
* [OPKR](https://github.com/openpilotkr)
* [Pfeiferj](https://github.com/pfeiferj)
* [ServerDummy](https://github.com/ServerDummy)
* [Twilsonco](https://github.com/twilsonco)

Licensing
------

openpilot is released under the MIT license. Some parts of the software are released under other licenses as specified.

Any user of this software shall indemnify and hold harmless Comma.ai, Inc. and its directors, officers, employees, agents, stockholders, affiliates, subcontractors and customers from and against all allegations, claims, actions, suits, demands, damages, liabilities, obligations, losses, settlements, judgments, costs and expenses (including without limitation attorneys’ fees and costs) which arise out of, relate to or result from any use of this software by user.

**THIS IS ALPHA QUALITY SOFTWARE FOR RESEARCH PURPOSES ONLY. THIS IS NOT A PRODUCT.
YOU ARE RESPONSIBLE FOR COMPLYING WITH LOCAL LAWS AND REGULATIONS.
NO WARRANTY EXPRESSED OR IMPLIED.**

---

<img src="https://d1qb2nb5cznatu.cloudfront.net/startups/i/1061157-bc7e9bf3b246ece7322e6ffe653f6af8-medium_jpg.jpg?buster=1458363130" width="75"></img> <img src="https://cdn-images-1.medium.com/max/1600/1*C87EjxGeMPrkTuVRVWVg4w.png" width="225"></img>

[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/FrogAi/FrogPilot)
![openpilot tests](https://github.com/commaai/openpilot/actions/workflows/selfdrive_tests.yaml/badge.svg)
[![codecov](https://codecov.io/gh/commaai/openpilot/branch/master/graph/badge.svg)](https://codecov.io/gh/commaai/openpilot)

## Install URL / Command Lists

### [< Dragonpilot beta3 >](https://github.com/reopenpilot/openpilot-archive/commits/dp-beta3-20240820-1123/)
```
https://smiskol.com/fork/dp/beta3
```
```
curl -fsSL https://bit.ly/reopenpilot | bash -s 'dp/beta3'
```

> <details><summary>Show older versions</summary>
>
> <br>
> 
> 
> > <details><summary>20240724-0804</summary>
> >
> > #### dp-beta3-20240724-0804
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-beta3-20240724-0804
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-beta3-20240724-0804
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240820-1123</summary>
> >
> > #### dp-beta3-20240820-1123
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-beta3-20240820-1123
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-beta3-20240820-1123
> > ```
> >
> > </details>
> >
>
> </details>



### [< Dragonpilot master3 >](https://github.com/reopenpilot/openpilot-archive/commits/dp-master3-20240820-1120/)
```
https://smiskol.com/fork/dp/master3
```
```
curl -fsSL https://bit.ly/reopenpilot | bash -s 'dp/master3'
```

> <details><summary>Show older versions</summary>
>
> <br>
> 
> 
> > <details><summary>20240724-0801</summary>
> >
> > #### dp-master3-20240724-0801
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240724-0801
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240724-0801
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240730-1404</summary>
> >
> > #### dp-master3-20240730-1404
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240730-1404
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240730-1404
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240730-1417</summary>
> >
> > #### dp-master3-20240730-1417
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240730-1417
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240730-1417
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-0654</summary>
> >
> > #### dp-master3-20240731-0654
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240731-0654
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240731-0654
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-1352</summary>
> >
> > #### dp-master3-20240731-1352
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240731-1352
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240731-1352
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-0926</summary>
> >
> > #### dp-master3-20240801-0926
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240801-0926
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240801-0926
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-0940</summary>
> >
> > #### dp-master3-20240801-0940
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240801-0940
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240801-0940
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-0945</summary>
> >
> > #### dp-master3-20240801-0945
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240801-0945
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240801-0945
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-0951</summary>
> >
> > #### dp-master3-20240801-0951
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240801-0951
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240801-0951
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-1000</summary>
> >
> > #### dp-master3-20240801-1000
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240801-1000
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240801-1000
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-0949</summary>
> >
> > #### dp-master3-20240802-0949
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240802-0949
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240802-0949
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1300</summary>
> >
> > #### dp-master3-20240802-1300
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240802-1300
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240802-1300
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-0208</summary>
> >
> > #### dp-master3-20240807-0208
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240807-0208
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240807-0208
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240820-1120</summary>
> >
> > #### dp-master3-20240820-1120
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-20240820-1120
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-20240820-1120
> > ```
> >
> > </details>
> >
>
> </details>



### [< Dragonpilot master3-sgo >](https://github.com/reopenpilot/openpilot-archive/commits/dp-master3-sgo-20240724-0821/)
```
https://smiskol.com/fork/dp/master3-sgo
```
```
curl -fsSL https://bit.ly/reopenpilot | bash -s 'dp/master3-sgo'
```

> <details><summary>Show older versions</summary>
>
> <br>
> 
> 
> > <details><summary>20240724-0821</summary>
> >
> > #### dp-master3-sgo-20240724-0821
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/dp-master3-sgo-20240724-0821
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s dp-master3-sgo-20240724-0821
> > ```
> >
> > </details>
> >
>
> </details>



### [< FrogPilot FrogPilot >](https://github.com/reopenpilot/openpilot-archive/commits/fp-FrogPilot-20251103-2257/)
```
https://smiskol.com/fork/fp/FrogPilot
```
```
curl -fsSL https://bit.ly/reopenpilot | bash -s 'fp/FrogPilot'
```

> <details><summary>Show older versions</summary>
>
> <br>
> 
> 
> > <details><summary>20240723-2120</summary>
> >
> > #### fp-FrogPilot-20240723-2120
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240723-2120
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240723-2120
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-0651</summary>
> >
> > #### fp-FrogPilot-20240801-0651
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240801-0651
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240801-0651
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-1742</summary>
> >
> > #### fp-FrogPilot-20240801-1742
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240801-1742
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240801-1742
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-2227</summary>
> >
> > #### fp-FrogPilot-20240801-2227
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240801-2227
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240801-2227
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-0317</summary>
> >
> > #### fp-FrogPilot-20240802-0317
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240802-0317
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240802-0317
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-2141</summary>
> >
> > #### fp-FrogPilot-20240802-2141
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240802-2141
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240802-2141
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-0125</summary>
> >
> > #### fp-FrogPilot-20240803-0125
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240803-0125
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240803-0125
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-1925</summary>
> >
> > #### fp-FrogPilot-20240803-1925
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240803-1925
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240803-1925
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-1941</summary>
> >
> > #### fp-FrogPilot-20240803-1941
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240803-1941
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240803-1941
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-2142</summary>
> >
> > #### fp-FrogPilot-20240803-2142
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240803-2142
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240803-2142
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-0112</summary>
> >
> > #### fp-FrogPilot-20240804-0112
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240804-0112
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240804-0112
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240815-2336</summary>
> >
> > #### fp-FrogPilot-20240815-2336
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240815-2336
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240815-2336
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240816-0020</summary>
> >
> > #### fp-FrogPilot-20240816-0020
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240816-0020
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240816-0020
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240819-0222</summary>
> >
> > #### fp-FrogPilot-20240819-0222
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240819-0222
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240819-0222
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240821-2223</summary>
> >
> > #### fp-FrogPilot-20240821-2223
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240821-2223
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240821-2223
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240822-0437</summary>
> >
> > #### fp-FrogPilot-20240822-0437
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240822-0437
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240822-0437
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240901-1535</summary>
> >
> > #### fp-FrogPilot-20240901-1535
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240901-1535
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240901-1535
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240901-1834</summary>
> >
> > #### fp-FrogPilot-20240901-1834
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240901-1834
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240901-1834
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240902-0835</summary>
> >
> > #### fp-FrogPilot-20240902-0835
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240902-0835
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240902-0835
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-0451</summary>
> >
> > #### fp-FrogPilot-20240904-0451
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240904-0451
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240904-0451
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-0724</summary>
> >
> > #### fp-FrogPilot-20240904-0724
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240904-0724
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240904-0724
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-1446</summary>
> >
> > #### fp-FrogPilot-20240904-1446
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240904-1446
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240904-1446
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-2058</summary>
> >
> > #### fp-FrogPilot-20240904-2058
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240904-2058
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240904-2058
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-1504</summary>
> >
> > #### fp-FrogPilot-20240905-1504
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240905-1504
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240905-1504
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-1613</summary>
> >
> > #### fp-FrogPilot-20240905-1613
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240905-1613
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240905-1613
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-1712</summary>
> >
> > #### fp-FrogPilot-20240905-1712
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240905-1712
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240905-1712
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-1735</summary>
> >
> > #### fp-FrogPilot-20240905-1735
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240905-1735
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240905-1735
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240906-1710</summary>
> >
> > #### fp-FrogPilot-20240906-1710
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240906-1710
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240906-1710
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240910-1822</summary>
> >
> > #### fp-FrogPilot-20240910-1822
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240910-1822
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240910-1822
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240911-0258</summary>
> >
> > #### fp-FrogPilot-20240911-0258
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240911-0258
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240911-0258
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240911-1248</summary>
> >
> > #### fp-FrogPilot-20240911-1248
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240911-1248
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240911-1248
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240911-2229</summary>
> >
> > #### fp-FrogPilot-20240911-2229
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240911-2229
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240911-2229
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-1958</summary>
> >
> > #### fp-FrogPilot-20240913-1958
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-1958
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-1958
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2011</summary>
> >
> > #### fp-FrogPilot-20240913-2011
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2011
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2011
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2016</summary>
> >
> > #### fp-FrogPilot-20240913-2016
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2016
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2016
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2022</summary>
> >
> > #### fp-FrogPilot-20240913-2022
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2022
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2022
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2034</summary>
> >
> > #### fp-FrogPilot-20240913-2034
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2034
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2034
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2046</summary>
> >
> > #### fp-FrogPilot-20240913-2046
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2046
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2046
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2049</summary>
> >
> > #### fp-FrogPilot-20240913-2049
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2049
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2049
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2209</summary>
> >
> > #### fp-FrogPilot-20240913-2209
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2209
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2209
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2236</summary>
> >
> > #### fp-FrogPilot-20240913-2236
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240913-2236
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240913-2236
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-0052</summary>
> >
> > #### fp-FrogPilot-20240914-0052
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240914-0052
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240914-0052
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-0543</summary>
> >
> > #### fp-FrogPilot-20240914-0543
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240914-0543
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240914-0543
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-1843</summary>
> >
> > #### fp-FrogPilot-20240914-1843
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240914-1843
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240914-1843
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-2213</summary>
> >
> > #### fp-FrogPilot-20240914-2213
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240914-2213
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240914-2213
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240915-2044</summary>
> >
> > #### fp-FrogPilot-20240915-2044
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20240915-2044
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20240915-2044
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-1705</summary>
> >
> > #### fp-FrogPilot-20241001-1705
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241001-1705
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241001-1705
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-1958</summary>
> >
> > #### fp-FrogPilot-20241001-1958
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241001-1958
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241001-1958
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-2020</summary>
> >
> > #### fp-FrogPilot-20241001-2020
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241001-2020
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241001-2020
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241002-1830</summary>
> >
> > #### fp-FrogPilot-20241002-1830
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241002-1830
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241002-1830
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241002-1838</summary>
> >
> > #### fp-FrogPilot-20241002-1838
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241002-1838
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241002-1838
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241002-1930</summary>
> >
> > #### fp-FrogPilot-20241002-1930
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241002-1930
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241002-1930
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241006-0245</summary>
> >
> > #### fp-FrogPilot-20241006-0245
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241006-0245
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241006-0245
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241006-0622</summary>
> >
> > #### fp-FrogPilot-20241006-0622
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241006-0622
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241006-0622
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241006-0645</summary>
> >
> > #### fp-FrogPilot-20241006-0645
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241006-0645
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241006-0645
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241008-0157</summary>
> >
> > #### fp-FrogPilot-20241008-0157
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241008-0157
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241008-0157
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241008-0522</summary>
> >
> > #### fp-FrogPilot-20241008-0522
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241008-0522
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241008-0522
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241013-2356</summary>
> >
> > #### fp-FrogPilot-20241013-2356
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241013-2356
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241013-2356
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241021-1713</summary>
> >
> > #### fp-FrogPilot-20241021-1713
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241021-1713
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241021-1713
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241021-1718</summary>
> >
> > #### fp-FrogPilot-20241021-1718
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241021-1718
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241021-1718
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241021-1728</summary>
> >
> > #### fp-FrogPilot-20241021-1728
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241021-1728
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241021-1728
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241022-0132</summary>
> >
> > #### fp-FrogPilot-20241022-0132
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241022-0132
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241022-0132
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241023-1957</summary>
> >
> > #### fp-FrogPilot-20241023-1957
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241023-1957
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241023-1957
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-1941</summary>
> >
> > #### fp-FrogPilot-20241101-1941
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241101-1941
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241101-1941
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2136</summary>
> >
> > #### fp-FrogPilot-20241101-2136
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241101-2136
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241101-2136
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2243</summary>
> >
> > #### fp-FrogPilot-20241101-2243
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241101-2243
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241101-2243
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2311</summary>
> >
> > #### fp-FrogPilot-20241101-2311
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241101-2311
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241101-2311
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2332</summary>
> >
> > #### fp-FrogPilot-20241101-2332
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241101-2332
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241101-2332
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0005</summary>
> >
> > #### fp-FrogPilot-20241102-0005
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241102-0005
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241102-0005
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0025</summary>
> >
> > #### fp-FrogPilot-20241102-0025
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241102-0025
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241102-0025
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0209</summary>
> >
> > #### fp-FrogPilot-20241102-0209
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241102-0209
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241102-0209
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0226</summary>
> >
> > #### fp-FrogPilot-20241102-0226
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241102-0226
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241102-0226
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0245</summary>
> >
> > #### fp-FrogPilot-20241102-0245
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241102-0245
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241102-0245
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0250</summary>
> >
> > #### fp-FrogPilot-20241102-0250
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241102-0250
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241102-0250
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-0254</summary>
> >
> > #### fp-FrogPilot-20241103-0254
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241103-0254
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241103-0254
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-1925</summary>
> >
> > #### fp-FrogPilot-20241103-1925
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241103-1925
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241103-1925
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-1929</summary>
> >
> > #### fp-FrogPilot-20241103-1929
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241103-1929
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241103-1929
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-1942</summary>
> >
> > #### fp-FrogPilot-20241103-1942
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241103-1942
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241103-1942
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-1951</summary>
> >
> > #### fp-FrogPilot-20241103-1951
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241103-1951
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241103-1951
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-2148</summary>
> >
> > #### fp-FrogPilot-20241103-2148
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241103-2148
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241103-2148
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241105-1825</summary>
> >
> > #### fp-FrogPilot-20241105-1825
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241105-1825
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241105-1825
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241109-2253</summary>
> >
> > #### fp-FrogPilot-20241109-2253
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241109-2253
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241109-2253
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241110-2045</summary>
> >
> > #### fp-FrogPilot-20241110-2045
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241110-2045
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241110-2045
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241116-2332</summary>
> >
> > #### fp-FrogPilot-20241116-2332
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241116-2332
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241116-2332
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241116-2343</summary>
> >
> > #### fp-FrogPilot-20241116-2343
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241116-2343
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241116-2343
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241117-0002</summary>
> >
> > #### fp-FrogPilot-20241117-0002
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241117-0002
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241117-0002
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241119-1001</summary>
> >
> > #### fp-FrogPilot-20241119-1001
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241119-1001
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241119-1001
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241119-1829</summary>
> >
> > #### fp-FrogPilot-20241119-1829
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241119-1829
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241119-1829
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2029</summary>
> >
> > #### fp-FrogPilot-20241124-2029
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241124-2029
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241124-2029
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2031</summary>
> >
> > #### fp-FrogPilot-20241124-2031
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241124-2031
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241124-2031
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2136</summary>
> >
> > #### fp-FrogPilot-20241124-2136
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241124-2136
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241124-2136
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2138</summary>
> >
> > #### fp-FrogPilot-20241124-2138
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241124-2138
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241124-2138
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241125-0031</summary>
> >
> > #### fp-FrogPilot-20241125-0031
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241125-0031
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241125-0031
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241125-0409</summary>
> >
> > #### fp-FrogPilot-20241125-0409
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241125-0409
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241125-0409
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241125-2217</summary>
> >
> > #### fp-FrogPilot-20241125-2217
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241125-2217
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241125-2217
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-0032</summary>
> >
> > #### fp-FrogPilot-20241126-0032
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241126-0032
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241126-0032
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-0110</summary>
> >
> > #### fp-FrogPilot-20241126-0110
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241126-0110
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241126-0110
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-0115</summary>
> >
> > #### fp-FrogPilot-20241126-0115
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241126-0115
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241126-0115
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-0158</summary>
> >
> > #### fp-FrogPilot-20241126-0158
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241126-0158
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241126-0158
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241201-0526</summary>
> >
> > #### fp-FrogPilot-20241201-0526
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241201-0526
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241201-0526
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241202-0338</summary>
> >
> > #### fp-FrogPilot-20241202-0338
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241202-0338
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241202-0338
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241202-0907</summary>
> >
> > #### fp-FrogPilot-20241202-0907
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241202-0907
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241202-0907
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241221-2138</summary>
> >
> > #### fp-FrogPilot-20241221-2138
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241221-2138
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241221-2138
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241221-2238</summary>
> >
> > #### fp-FrogPilot-20241221-2238
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20241221-2238
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20241221-2238
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250102-0624</summary>
> >
> > #### fp-FrogPilot-20250102-0624
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250102-0624
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250102-0624
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250102-0659</summary>
> >
> > #### fp-FrogPilot-20250102-0659
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250102-0659
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250102-0659
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250118-0834</summary>
> >
> > #### fp-FrogPilot-20250118-0834
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250118-0834
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250118-0834
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250125-2345</summary>
> >
> > #### fp-FrogPilot-20250125-2345
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250125-2345
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250125-2345
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250126-0228</summary>
> >
> > #### fp-FrogPilot-20250126-0228
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250126-0228
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250126-0228
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250126-0447</summary>
> >
> > #### fp-FrogPilot-20250126-0447
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250126-0447
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250126-0447
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250127-0330</summary>
> >
> > #### fp-FrogPilot-20250127-0330
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250127-0330
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250127-0330
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250127-0336</summary>
> >
> > #### fp-FrogPilot-20250127-0336
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250127-0336
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250127-0336
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250127-0632</summary>
> >
> > #### fp-FrogPilot-20250127-0632
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250127-0632
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250127-0632
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-0808</summary>
> >
> > #### fp-FrogPilot-20250128-0808
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250128-0808
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250128-0808
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-1858</summary>
> >
> > #### fp-FrogPilot-20250128-1858
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250128-1858
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250128-1858
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-1900</summary>
> >
> > #### fp-FrogPilot-20250128-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250128-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250128-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-1952</summary>
> >
> > #### fp-FrogPilot-20250128-1952
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250128-1952
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250128-1952
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1200</summary>
> >
> > #### fp-FrogPilot-20250205-1200
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-1200
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-1200
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1300</summary>
> >
> > #### fp-FrogPilot-20250205-1300
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-1300
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-1300
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1822</summary>
> >
> > #### fp-FrogPilot-20250205-1822
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-1822
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-1822
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1911</summary>
> >
> > #### fp-FrogPilot-20250205-1911
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-1911
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-1911
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1923</summary>
> >
> > #### fp-FrogPilot-20250205-1923
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-1923
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-1923
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1935</summary>
> >
> > #### fp-FrogPilot-20250205-1935
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-1935
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-1935
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-2009</summary>
> >
> > #### fp-FrogPilot-20250205-2009
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-2009
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-2009
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-2222</summary>
> >
> > #### fp-FrogPilot-20250205-2222
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250205-2222
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250205-2222
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250208-1900</summary>
> >
> > #### fp-FrogPilot-20250208-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250208-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250208-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250214-2038</summary>
> >
> > #### fp-FrogPilot-20250214-2038
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250214-2038
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250214-2038
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250219-0353</summary>
> >
> > #### fp-FrogPilot-20250219-0353
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250219-0353
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250219-0353
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250220-1953</summary>
> >
> > #### fp-FrogPilot-20250220-1953
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250220-1953
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250220-1953
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250220-2101</summary>
> >
> > #### fp-FrogPilot-20250220-2101
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250220-2101
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250220-2101
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250221-1916</summary>
> >
> > #### fp-FrogPilot-20250221-1916
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250221-1916
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250221-1916
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250221-1932</summary>
> >
> > #### fp-FrogPilot-20250221-1932
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250221-1932
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250221-1932
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250226-2037</summary>
> >
> > #### fp-FrogPilot-20250226-2037
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250226-2037
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250226-2037
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250308-1915</summary>
> >
> > #### fp-FrogPilot-20250308-1915
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250308-1915
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250308-1915
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250310-0211</summary>
> >
> > #### fp-FrogPilot-20250310-0211
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250310-0211
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250310-0211
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250310-0215</summary>
> >
> > #### fp-FrogPilot-20250310-0215
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250310-0215
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250310-0215
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250315-1915</summary>
> >
> > #### fp-FrogPilot-20250315-1915
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250315-1915
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250315-1915
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250315-1917</summary>
> >
> > #### fp-FrogPilot-20250315-1917
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250315-1917
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250315-1917
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250317-1957</summary>
> >
> > #### fp-FrogPilot-20250317-1957
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250317-1957
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250317-1957
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250318-2056</summary>
> >
> > #### fp-FrogPilot-20250318-2056
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250318-2056
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250318-2056
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250320-1943</summary>
> >
> > #### fp-FrogPilot-20250320-1943
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250320-1943
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250320-1943
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250322-1848</summary>
> >
> > #### fp-FrogPilot-20250322-1848
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250322-1848
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250322-1848
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250329-1900</summary>
> >
> > #### fp-FrogPilot-20250329-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250329-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250329-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-1900</summary>
> >
> > #### fp-FrogPilot-20250412-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250412-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250412-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-2149</summary>
> >
> > #### fp-FrogPilot-20250412-2149
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250412-2149
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250412-2149
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-2242</summary>
> >
> > #### fp-FrogPilot-20250412-2242
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250412-2242
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250412-2242
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250426-1900</summary>
> >
> > #### fp-FrogPilot-20250426-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250426-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250426-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250621-1900</summary>
> >
> > #### fp-FrogPilot-20250621-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250621-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250621-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250621-2126</summary>
> >
> > #### fp-FrogPilot-20250621-2126
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250621-2126
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250621-2126
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250621-2127</summary>
> >
> > #### fp-FrogPilot-20250621-2127
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250621-2127
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250621-2127
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250622-0353</summary>
> >
> > #### fp-FrogPilot-20250622-0353
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250622-0353
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250622-0353
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250622-1900</summary>
> >
> > #### fp-FrogPilot-20250622-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250622-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250622-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250622-2358</summary>
> >
> > #### fp-FrogPilot-20250622-2358
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250622-2358
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250622-2358
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0004</summary>
> >
> > #### fp-FrogPilot-20250623-0004
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250623-0004
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250623-0004
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0052</summary>
> >
> > #### fp-FrogPilot-20250623-0052
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250623-0052
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250623-0052
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0502</summary>
> >
> > #### fp-FrogPilot-20250623-0502
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250623-0502
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250623-0502
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0551</summary>
> >
> > #### fp-FrogPilot-20250623-0551
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250623-0551
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250623-0551
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0630</summary>
> >
> > #### fp-FrogPilot-20250623-0630
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250623-0630
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250623-0630
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250624-0829</summary>
> >
> > #### fp-FrogPilot-20250624-0829
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250624-0829
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250624-0829
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250624-0843</summary>
> >
> > #### fp-FrogPilot-20250624-0843
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250624-0843
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250624-0843
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250712-1900</summary>
> >
> > #### fp-FrogPilot-20250712-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250712-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250712-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250729-2301</summary>
> >
> > #### fp-FrogPilot-20250729-2301
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250729-2301
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250729-2301
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250729-2308</summary>
> >
> > #### fp-FrogPilot-20250729-2308
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250729-2308
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250729-2308
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250729-2313</summary>
> >
> > #### fp-FrogPilot-20250729-2313
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250729-2313
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250729-2313
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250729-2326</summary>
> >
> > #### fp-FrogPilot-20250729-2326
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250729-2326
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250729-2326
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250729-2329</summary>
> >
> > #### fp-FrogPilot-20250729-2329
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250729-2329
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250729-2329
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250729-2337</summary>
> >
> > #### fp-FrogPilot-20250729-2337
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250729-2337
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250729-2337
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250809-1900</summary>
> >
> > #### fp-FrogPilot-20250809-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250809-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250809-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250810-1013</summary>
> >
> > #### fp-FrogPilot-20250810-1013
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250810-1013
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250810-1013
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250811-0315</summary>
> >
> > #### fp-FrogPilot-20250811-0315
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250811-0315
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250811-0315
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250811-0804</summary>
> >
> > #### fp-FrogPilot-20250811-0804
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250811-0804
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250811-0804
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250813-0800</summary>
> >
> > #### fp-FrogPilot-20250813-0800
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250813-0800
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250813-0800
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250813-0809</summary>
> >
> > #### fp-FrogPilot-20250813-0809
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250813-0809
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250813-0809
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250813-0822</summary>
> >
> > #### fp-FrogPilot-20250813-0822
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250813-0822
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250813-0822
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250813-0829</summary>
> >
> > #### fp-FrogPilot-20250813-0829
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250813-0829
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250813-0829
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250813-0859</summary>
> >
> > #### fp-FrogPilot-20250813-0859
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250813-0859
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250813-0859
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250813-2029</summary>
> >
> > #### fp-FrogPilot-20250813-2029
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250813-2029
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250813-2029
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250813-2151</summary>
> >
> > #### fp-FrogPilot-20250813-2151
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250813-2151
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250813-2151
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250814-0352</summary>
> >
> > #### fp-FrogPilot-20250814-0352
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250814-0352
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250814-0352
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250818-2101</summary>
> >
> > #### fp-FrogPilot-20250818-2101
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250818-2101
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250818-2101
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250818-2134</summary>
> >
> > #### fp-FrogPilot-20250818-2134
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250818-2134
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250818-2134
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250825-0611</summary>
> >
> > #### fp-FrogPilot-20250825-0611
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250825-0611
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250825-0611
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250829-1643</summary>
> >
> > #### fp-FrogPilot-20250829-1643
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250829-1643
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250829-1643
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250911-1728</summary>
> >
> > #### fp-FrogPilot-20250911-1728
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250911-1728
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250911-1728
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250927-0405</summary>
> >
> > #### fp-FrogPilot-20250927-0405
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250927-0405
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250927-0405
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250927-1900</summary>
> >
> > #### fp-FrogPilot-20250927-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250927-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250927-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250927-2242</summary>
> >
> > #### fp-FrogPilot-20250927-2242
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20250927-2242
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20250927-2242
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251001-2208</summary>
> >
> > #### fp-FrogPilot-20251001-2208
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251001-2208
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251001-2208
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251001-2215</summary>
> >
> > #### fp-FrogPilot-20251001-2215
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251001-2215
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251001-2215
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251001-2216</summary>
> >
> > #### fp-FrogPilot-20251001-2216
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251001-2216
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251001-2216
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251001-2227</summary>
> >
> > #### fp-FrogPilot-20251001-2227
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251001-2227
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251001-2227
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251002-0511</summary>
> >
> > #### fp-FrogPilot-20251002-0511
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251002-0511
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251002-0511
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251018-1900</summary>
> >
> > #### fp-FrogPilot-20251018-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251018-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251018-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251024-0001</summary>
> >
> > #### fp-FrogPilot-20251024-0001
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251024-0001
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251024-0001
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251024-1721</summary>
> >
> > #### fp-FrogPilot-20251024-1721
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251024-1721
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251024-1721
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-0026</summary>
> >
> > #### fp-FrogPilot-20251028-0026
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251028-0026
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251028-0026
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-0027</summary>
> >
> > #### fp-FrogPilot-20251028-0027
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251028-0027
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251028-0027
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2027</summary>
> >
> > #### fp-FrogPilot-20251028-2027
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251028-2027
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251028-2027
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2113</summary>
> >
> > #### fp-FrogPilot-20251028-2113
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251028-2113
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251028-2113
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251031-2023</summary>
> >
> > #### fp-FrogPilot-20251031-2023
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251031-2023
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251031-2023
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251101-0443</summary>
> >
> > #### fp-FrogPilot-20251101-0443
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251101-0443
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251101-0443
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251101-1900</summary>
> >
> > #### fp-FrogPilot-20251101-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251101-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251101-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251103-2257</summary>
> >
> > #### fp-FrogPilot-20251103-2257
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251103-2257
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251103-2257
> > ```
> >
> > </details>
> >
>
> </details>



### [< FrogPilot FrogPilot-Staging >](https://github.com/reopenpilot/openpilot-archive/commits/fp-FrogPilot-Staging-20251109-0617/)
```
https://smiskol.com/fork/fp/FrogPilot-Staging
```
```
curl -fsSL https://bit.ly/reopenpilot | bash -s 'fp/FrogPilot-Staging'
```

> <details><summary>Show older versions</summary>
>
> <br>
> 
> 
> > <details><summary>20240729-2257</summary>
> >
> > #### fp-FrogPilot-Staging-20240729-2257
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240729-2257
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240729-2257
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240730-0805</summary>
> >
> > #### fp-FrogPilot-Staging-20240730-0805
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240730-0805
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240730-0805
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240730-1912</summary>
> >
> > #### fp-FrogPilot-Staging-20240730-1912
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240730-1912
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240730-1912
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-0144</summary>
> >
> > #### fp-FrogPilot-Staging-20240731-0144
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240731-0144
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240731-0144
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-0804</summary>
> >
> > #### fp-FrogPilot-Staging-20240731-0804
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240731-0804
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240731-0804
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-0651</summary>
> >
> > #### fp-FrogPilot-Staging-20240801-0651
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240801-0651
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240801-0651
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-1742</summary>
> >
> > #### fp-FrogPilot-Staging-20240801-1742
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240801-1742
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240801-1742
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-2227</summary>
> >
> > #### fp-FrogPilot-Staging-20240801-2227
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240801-2227
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240801-2227
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-2134</summary>
> >
> > #### fp-FrogPilot-Staging-20240802-2134
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240802-2134
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240802-2134
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-0125</summary>
> >
> > #### fp-FrogPilot-Staging-20240803-0125
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240803-0125
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240803-0125
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-1924</summary>
> >
> > #### fp-FrogPilot-Staging-20240803-1924
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240803-1924
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240803-1924
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-1941</summary>
> >
> > #### fp-FrogPilot-Staging-20240803-1941
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240803-1941
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240803-1941
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-2142</summary>
> >
> > #### fp-FrogPilot-Staging-20240803-2142
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240803-2142
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240803-2142
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-0112</summary>
> >
> > #### fp-FrogPilot-Staging-20240804-0112
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240804-0112
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240804-0112
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-2029</summary>
> >
> > #### fp-FrogPilot-Staging-20240804-2029
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240804-2029
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240804-2029
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-2235</summary>
> >
> > #### fp-FrogPilot-Staging-20240804-2235
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240804-2235
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240804-2235
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-0742</summary>
> >
> > #### fp-FrogPilot-Staging-20240810-0742
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240810-0742
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240810-0742
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-1018</summary>
> >
> > #### fp-FrogPilot-Staging-20240810-1018
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240810-1018
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240810-1018
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240814-1911</summary>
> >
> > #### fp-FrogPilot-Staging-20240814-1911
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240814-1911
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240814-1911
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240817-0410</summary>
> >
> > #### fp-FrogPilot-Staging-20240817-0410
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240817-0410
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240817-0410
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240817-0455</summary>
> >
> > #### fp-FrogPilot-Staging-20240817-0455
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240817-0455
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240817-0455
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240819-0440</summary>
> >
> > #### fp-FrogPilot-Staging-20240819-0440
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240819-0440
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240819-0440
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240824-0637</summary>
> >
> > #### fp-FrogPilot-Staging-20240824-0637
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240824-0637
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240824-0637
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240824-1036</summary>
> >
> > #### fp-FrogPilot-Staging-20240824-1036
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240824-1036
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240824-1036
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240824-1303</summary>
> >
> > #### fp-FrogPilot-Staging-20240824-1303
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240824-1303
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240824-1303
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240824-1535</summary>
> >
> > #### fp-FrogPilot-Staging-20240824-1535
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240824-1535
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240824-1535
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240824-2358</summary>
> >
> > #### fp-FrogPilot-Staging-20240824-2358
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240824-2358
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240824-2358
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240825-0056</summary>
> >
> > #### fp-FrogPilot-Staging-20240825-0056
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240825-0056
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240825-0056
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240825-1522</summary>
> >
> > #### fp-FrogPilot-Staging-20240825-1522
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240825-1522
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240825-1522
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0727</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0727
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0727
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0727
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0744</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0744
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0744
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0744
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0750</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0750
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0750
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0750
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0754</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0754
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0754
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0754
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0801</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0801
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0801
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0801
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0803</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0803
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0803
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0803
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0812</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0812
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0812
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0812
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0815</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0815
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0815
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0815
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0821</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0821
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0821
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0821
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0828</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0828
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0828
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0828
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0834</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0834
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0834
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0834
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0841</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0841
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0841
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0841
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0847</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0847
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0847
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0847
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0853</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0853
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0853
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0853
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0857</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0857
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0857
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0857
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0903</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0903
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0903
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0903
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0907</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0907
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0907
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0907
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0912</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0912
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0912
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0912
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0919</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0919
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0919
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0919
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0926</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0926
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0926
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0926
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0928</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0928
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0928
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0928
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0936</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0936
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0936
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0936
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0941</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0941
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0941
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0941
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-0947</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-0947
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-0947
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-0947
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-1003</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-1003
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-1003
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-1003
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-1008</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-1008
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-1008
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-1008
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-1011</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-1011
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-1011
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-1011
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-1020</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-1020
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-1020
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-1020
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-1025</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-1025
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-1025
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-1025
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240826-1417</summary>
> >
> > #### fp-FrogPilot-Staging-20240826-1417
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240826-1417
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240826-1417
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240828-0632</summary>
> >
> > #### fp-FrogPilot-Staging-20240828-0632
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240828-0632
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240828-0632
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240828-2225</summary>
> >
> > #### fp-FrogPilot-Staging-20240828-2225
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240828-2225
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240828-2225
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240828-2235</summary>
> >
> > #### fp-FrogPilot-Staging-20240828-2235
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240828-2235
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240828-2235
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240830-1032</summary>
> >
> > #### fp-FrogPilot-Staging-20240830-1032
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240830-1032
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240830-1032
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240831-1731</summary>
> >
> > #### fp-FrogPilot-Staging-20240831-1731
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240831-1731
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240831-1731
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240831-1928</summary>
> >
> > #### fp-FrogPilot-Staging-20240831-1928
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240831-1928
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240831-1928
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240831-1936</summary>
> >
> > #### fp-FrogPilot-Staging-20240831-1936
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240831-1936
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240831-1936
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240831-2038</summary>
> >
> > #### fp-FrogPilot-Staging-20240831-2038
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240831-2038
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240831-2038
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240901-1108</summary>
> >
> > #### fp-FrogPilot-Staging-20240901-1108
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240901-1108
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240901-1108
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240901-1535</summary>
> >
> > #### fp-FrogPilot-Staging-20240901-1535
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240901-1535
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240901-1535
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240901-1834</summary>
> >
> > #### fp-FrogPilot-Staging-20240901-1834
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240901-1834
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240901-1834
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240901-1921</summary>
> >
> > #### fp-FrogPilot-Staging-20240901-1921
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240901-1921
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240901-1921
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240902-0834</summary>
> >
> > #### fp-FrogPilot-Staging-20240902-0834
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240902-0834
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240902-0834
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-0510</summary>
> >
> > #### fp-FrogPilot-Staging-20240904-0510
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240904-0510
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240904-0510
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-0726</summary>
> >
> > #### fp-FrogPilot-Staging-20240904-0726
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240904-0726
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240904-0726
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-1446</summary>
> >
> > #### fp-FrogPilot-Staging-20240904-1446
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240904-1446
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240904-1446
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240904-1540</summary>
> >
> > #### fp-FrogPilot-Staging-20240904-1540
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240904-1540
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240904-1540
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-1713</summary>
> >
> > #### fp-FrogPilot-Staging-20240905-1713
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240905-1713
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240905-1713
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-1735</summary>
> >
> > #### fp-FrogPilot-Staging-20240905-1735
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240905-1735
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240905-1735
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-2121</summary>
> >
> > #### fp-FrogPilot-Staging-20240905-2121
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240905-2121
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240905-2121
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240905-2314</summary>
> >
> > #### fp-FrogPilot-Staging-20240905-2314
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240905-2314
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240905-2314
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240906-1436</summary>
> >
> > #### fp-FrogPilot-Staging-20240906-1436
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240906-1436
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240906-1436
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240906-1712</summary>
> >
> > #### fp-FrogPilot-Staging-20240906-1712
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240906-1712
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240906-1712
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240906-2129</summary>
> >
> > #### fp-FrogPilot-Staging-20240906-2129
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240906-2129
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240906-2129
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240910-1819</summary>
> >
> > #### fp-FrogPilot-Staging-20240910-1819
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240910-1819
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240910-1819
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240911-0318</summary>
> >
> > #### fp-FrogPilot-Staging-20240911-0318
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240911-0318
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240911-0318
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-1720</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-1720
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-1720
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-1720
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-1855</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-1855
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-1855
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-1855
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-1958</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-1958
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-1958
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-1958
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2022</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-2022
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-2022
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-2022
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2026</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-2026
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-2026
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-2026
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2036</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-2036
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-2036
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-2036
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2116</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-2116
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-2116
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-2116
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2212</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-2212
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-2212
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-2212
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240913-2235</summary>
> >
> > #### fp-FrogPilot-Staging-20240913-2235
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240913-2235
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240913-2235
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-0055</summary>
> >
> > #### fp-FrogPilot-Staging-20240914-0055
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240914-0055
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240914-0055
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-0544</summary>
> >
> > #### fp-FrogPilot-Staging-20240914-0544
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240914-0544
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240914-0544
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-1732</summary>
> >
> > #### fp-FrogPilot-Staging-20240914-1732
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240914-1732
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240914-1732
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240914-2027</summary>
> >
> > #### fp-FrogPilot-Staging-20240914-2027
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240914-2027
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240914-2027
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240915-1845</summary>
> >
> > #### fp-FrogPilot-Staging-20240915-1845
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240915-1845
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240915-1845
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240915-1924</summary>
> >
> > #### fp-FrogPilot-Staging-20240915-1924
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240915-1924
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240915-1924
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240916-0247</summary>
> >
> > #### fp-FrogPilot-Staging-20240916-0247
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240916-0247
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240916-0247
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240916-0313</summary>
> >
> > #### fp-FrogPilot-Staging-20240916-0313
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240916-0313
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240916-0313
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240916-1622</summary>
> >
> > #### fp-FrogPilot-Staging-20240916-1622
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240916-1622
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240916-1622
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240916-1651</summary>
> >
> > #### fp-FrogPilot-Staging-20240916-1651
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240916-1651
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240916-1651
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240916-2139</summary>
> >
> > #### fp-FrogPilot-Staging-20240916-2139
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240916-2139
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240916-2139
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240916-2252</summary>
> >
> > #### fp-FrogPilot-Staging-20240916-2252
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240916-2252
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240916-2252
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240916-2344</summary>
> >
> > #### fp-FrogPilot-Staging-20240916-2344
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240916-2344
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240916-2344
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240917-0141</summary>
> >
> > #### fp-FrogPilot-Staging-20240917-0141
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240917-0141
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240917-0141
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240917-0155</summary>
> >
> > #### fp-FrogPilot-Staging-20240917-0155
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240917-0155
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240917-0155
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240917-0201</summary>
> >
> > #### fp-FrogPilot-Staging-20240917-0201
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240917-0201
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240917-0201
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240917-0517</summary>
> >
> > #### fp-FrogPilot-Staging-20240917-0517
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240917-0517
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240917-0517
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240918-0853</summary>
> >
> > #### fp-FrogPilot-Staging-20240918-0853
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240918-0853
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240918-0853
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240920-1639</summary>
> >
> > #### fp-FrogPilot-Staging-20240920-1639
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240920-1639
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240920-1639
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240921-0410</summary>
> >
> > #### fp-FrogPilot-Staging-20240921-0410
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240921-0410
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240921-0410
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240921-0741</summary>
> >
> > #### fp-FrogPilot-Staging-20240921-0741
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240921-0741
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240921-0741
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240921-0758</summary>
> >
> > #### fp-FrogPilot-Staging-20240921-0758
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240921-0758
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240921-0758
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240925-0754</summary>
> >
> > #### fp-FrogPilot-Staging-20240925-0754
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240925-0754
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240925-0754
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240925-1949</summary>
> >
> > #### fp-FrogPilot-Staging-20240925-1949
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240925-1949
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240925-1949
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240925-2010</summary>
> >
> > #### fp-FrogPilot-Staging-20240925-2010
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240925-2010
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240925-2010
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240925-2152</summary>
> >
> > #### fp-FrogPilot-Staging-20240925-2152
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240925-2152
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240925-2152
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240925-2208</summary>
> >
> > #### fp-FrogPilot-Staging-20240925-2208
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240925-2208
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240925-2208
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240926-0135</summary>
> >
> > #### fp-FrogPilot-Staging-20240926-0135
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240926-0135
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240926-0135
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240926-0200</summary>
> >
> > #### fp-FrogPilot-Staging-20240926-0200
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240926-0200
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240926-0200
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240926-0902</summary>
> >
> > #### fp-FrogPilot-Staging-20240926-0902
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240926-0902
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240926-0902
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240926-2348</summary>
> >
> > #### fp-FrogPilot-Staging-20240926-2348
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240926-2348
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240926-2348
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240927-0925</summary>
> >
> > #### fp-FrogPilot-Staging-20240927-0925
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240927-0925
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240927-0925
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240927-1411</summary>
> >
> > #### fp-FrogPilot-Staging-20240927-1411
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240927-1411
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240927-1411
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240927-2133</summary>
> >
> > #### fp-FrogPilot-Staging-20240927-2133
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240927-2133
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240927-2133
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240928-0511</summary>
> >
> > #### fp-FrogPilot-Staging-20240928-0511
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240928-0511
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240928-0511
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240928-0645</summary>
> >
> > #### fp-FrogPilot-Staging-20240928-0645
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240928-0645
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240928-0645
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240928-0732</summary>
> >
> > #### fp-FrogPilot-Staging-20240928-0732
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240928-0732
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240928-0732
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240928-1045</summary>
> >
> > #### fp-FrogPilot-Staging-20240928-1045
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240928-1045
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240928-1045
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240928-2222</summary>
> >
> > #### fp-FrogPilot-Staging-20240928-2222
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240928-2222
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240928-2222
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240929-2049</summary>
> >
> > #### fp-FrogPilot-Staging-20240929-2049
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240929-2049
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240929-2049
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240930-0102</summary>
> >
> > #### fp-FrogPilot-Staging-20240930-0102
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240930-0102
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240930-0102
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240930-2045</summary>
> >
> > #### fp-FrogPilot-Staging-20240930-2045
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20240930-2045
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20240930-2045
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-0223</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-0223
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-0223
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-0223
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-0232</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-0232
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-0232
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-0232
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-0315</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-0315
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-0315
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-0315
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-0333</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-0333
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-0333
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-0333
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-0353</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-0353
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-0353
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-0353
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-1705</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-1705
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-1705
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-1705
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-1958</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-1958
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-1958
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-1958
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241001-2020</summary>
> >
> > #### fp-FrogPilot-Staging-20241001-2020
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241001-2020
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241001-2020
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241002-1034</summary>
> >
> > #### fp-FrogPilot-Staging-20241002-1034
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241002-1034
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241002-1034
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241002-1828</summary>
> >
> > #### fp-FrogPilot-Staging-20241002-1828
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241002-1828
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241002-1828
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241002-1930</summary>
> >
> > #### fp-FrogPilot-Staging-20241002-1930
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241002-1930
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241002-1930
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241004-1723</summary>
> >
> > #### fp-FrogPilot-Staging-20241004-1723
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241004-1723
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241004-1723
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241004-1729</summary>
> >
> > #### fp-FrogPilot-Staging-20241004-1729
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241004-1729
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241004-1729
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241004-1936</summary>
> >
> > #### fp-FrogPilot-Staging-20241004-1936
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241004-1936
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241004-1936
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241005-0552</summary>
> >
> > #### fp-FrogPilot-Staging-20241005-0552
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241005-0552
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241005-0552
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241005-1105</summary>
> >
> > #### fp-FrogPilot-Staging-20241005-1105
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241005-1105
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241005-1105
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241005-1254</summary>
> >
> > #### fp-FrogPilot-Staging-20241005-1254
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241005-1254
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241005-1254
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241005-2328</summary>
> >
> > #### fp-FrogPilot-Staging-20241005-2328
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241005-2328
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241005-2328
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241006-0245</summary>
> >
> > #### fp-FrogPilot-Staging-20241006-0245
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241006-0245
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241006-0245
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241006-0622</summary>
> >
> > #### fp-FrogPilot-Staging-20241006-0622
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241006-0622
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241006-0622
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241006-0645</summary>
> >
> > #### fp-FrogPilot-Staging-20241006-0645
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241006-0645
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241006-0645
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241007-0744</summary>
> >
> > #### fp-FrogPilot-Staging-20241007-0744
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241007-0744
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241007-0744
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241008-0157</summary>
> >
> > #### fp-FrogPilot-Staging-20241008-0157
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241008-0157
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241008-0157
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241008-0522</summary>
> >
> > #### fp-FrogPilot-Staging-20241008-0522
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241008-0522
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241008-0522
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241008-0527</summary>
> >
> > #### fp-FrogPilot-Staging-20241008-0527
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241008-0527
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241008-0527
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241013-2329</summary>
> >
> > #### fp-FrogPilot-Staging-20241013-2329
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241013-2329
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241013-2329
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241013-2356</summary>
> >
> > #### fp-FrogPilot-Staging-20241013-2356
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241013-2356
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241013-2356
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241018-0629</summary>
> >
> > #### fp-FrogPilot-Staging-20241018-0629
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241018-0629
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241018-0629
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241019-0926</summary>
> >
> > #### fp-FrogPilot-Staging-20241019-0926
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241019-0926
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241019-0926
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241021-1713</summary>
> >
> > #### fp-FrogPilot-Staging-20241021-1713
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241021-1713
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241021-1713
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241021-1718</summary>
> >
> > #### fp-FrogPilot-Staging-20241021-1718
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241021-1718
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241021-1718
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241021-1728</summary>
> >
> > #### fp-FrogPilot-Staging-20241021-1728
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241021-1728
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241021-1728
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241021-2127</summary>
> >
> > #### fp-FrogPilot-Staging-20241021-2127
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241021-2127
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241021-2127
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241022-0132</summary>
> >
> > #### fp-FrogPilot-Staging-20241022-0132
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241022-0132
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241022-0132
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241023-1959</summary>
> >
> > #### fp-FrogPilot-Staging-20241023-1959
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241023-1959
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241023-1959
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241031-0447</summary>
> >
> > #### fp-FrogPilot-Staging-20241031-0447
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241031-0447
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241031-0447
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-1927</summary>
> >
> > #### fp-FrogPilot-Staging-20241101-1927
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241101-1927
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241101-1927
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-1941</summary>
> >
> > #### fp-FrogPilot-Staging-20241101-1941
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241101-1941
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241101-1941
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2136</summary>
> >
> > #### fp-FrogPilot-Staging-20241101-2136
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241101-2136
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241101-2136
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2243</summary>
> >
> > #### fp-FrogPilot-Staging-20241101-2243
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241101-2243
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241101-2243
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2311</summary>
> >
> > #### fp-FrogPilot-Staging-20241101-2311
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241101-2311
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241101-2311
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241101-2332</summary>
> >
> > #### fp-FrogPilot-Staging-20241101-2332
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241101-2332
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241101-2332
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0005</summary>
> >
> > #### fp-FrogPilot-Staging-20241102-0005
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241102-0005
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241102-0005
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0025</summary>
> >
> > #### fp-FrogPilot-Staging-20241102-0025
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241102-0025
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241102-0025
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0209</summary>
> >
> > #### fp-FrogPilot-Staging-20241102-0209
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241102-0209
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241102-0209
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0226</summary>
> >
> > #### fp-FrogPilot-Staging-20241102-0226
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241102-0226
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241102-0226
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0245</summary>
> >
> > #### fp-FrogPilot-Staging-20241102-0245
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241102-0245
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241102-0245
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241102-0250</summary>
> >
> > #### fp-FrogPilot-Staging-20241102-0250
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241102-0250
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241102-0250
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-0254</summary>
> >
> > #### fp-FrogPilot-Staging-20241103-0254
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241103-0254
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241103-0254
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-1925</summary>
> >
> > #### fp-FrogPilot-Staging-20241103-1925
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241103-1925
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241103-1925
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-1929</summary>
> >
> > #### fp-FrogPilot-Staging-20241103-1929
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241103-1929
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241103-1929
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-1951</summary>
> >
> > #### fp-FrogPilot-Staging-20241103-1951
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241103-1951
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241103-1951
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241103-2148</summary>
> >
> > #### fp-FrogPilot-Staging-20241103-2148
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241103-2148
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241103-2148
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241106-1847</summary>
> >
> > #### fp-FrogPilot-Staging-20241106-1847
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241106-1847
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241106-1847
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241107-1746</summary>
> >
> > #### fp-FrogPilot-Staging-20241107-1746
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241107-1746
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241107-1746
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241108-2003</summary>
> >
> > #### fp-FrogPilot-Staging-20241108-2003
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241108-2003
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241108-2003
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241109-2253</summary>
> >
> > #### fp-FrogPilot-Staging-20241109-2253
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241109-2253
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241109-2253
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241110-2045</summary>
> >
> > #### fp-FrogPilot-Staging-20241110-2045
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241110-2045
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241110-2045
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241116-2343</summary>
> >
> > #### fp-FrogPilot-Staging-20241116-2343
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241116-2343
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241116-2343
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241117-0002</summary>
> >
> > #### fp-FrogPilot-Staging-20241117-0002
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241117-0002
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241117-0002
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241118-0905</summary>
> >
> > #### fp-FrogPilot-Staging-20241118-0905
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241118-0905
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241118-0905
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241121-1815</summary>
> >
> > #### fp-FrogPilot-Staging-20241121-1815
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241121-1815
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241121-1815
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241122-0148</summary>
> >
> > #### fp-FrogPilot-Staging-20241122-0148
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241122-0148
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241122-0148
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241122-0150</summary>
> >
> > #### fp-FrogPilot-Staging-20241122-0150
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241122-0150
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241122-0150
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241122-0514</summary>
> >
> > #### fp-FrogPilot-Staging-20241122-0514
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241122-0514
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241122-0514
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241122-0519</summary>
> >
> > #### fp-FrogPilot-Staging-20241122-0519
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241122-0519
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241122-0519
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241122-2040</summary>
> >
> > #### fp-FrogPilot-Staging-20241122-2040
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241122-2040
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241122-2040
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2001</summary>
> >
> > #### fp-FrogPilot-Staging-20241124-2001
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241124-2001
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241124-2001
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2005</summary>
> >
> > #### fp-FrogPilot-Staging-20241124-2005
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241124-2005
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241124-2005
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2029</summary>
> >
> > #### fp-FrogPilot-Staging-20241124-2029
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241124-2029
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241124-2029
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2035</summary>
> >
> > #### fp-FrogPilot-Staging-20241124-2035
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241124-2035
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241124-2035
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241124-2145</summary>
> >
> > #### fp-FrogPilot-Staging-20241124-2145
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241124-2145
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241124-2145
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241125-0031</summary>
> >
> > #### fp-FrogPilot-Staging-20241125-0031
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241125-0031
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241125-0031
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241125-0409</summary>
> >
> > #### fp-FrogPilot-Staging-20241125-0409
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241125-0409
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241125-0409
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241125-2217</summary>
> >
> > #### fp-FrogPilot-Staging-20241125-2217
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241125-2217
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241125-2217
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-0032</summary>
> >
> > #### fp-FrogPilot-Staging-20241126-0032
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241126-0032
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241126-0032
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-0115</summary>
> >
> > #### fp-FrogPilot-Staging-20241126-0115
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241126-0115
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241126-0115
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-0158</summary>
> >
> > #### fp-FrogPilot-Staging-20241126-0158
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241126-0158
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241126-0158
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-1844</summary>
> >
> > #### fp-FrogPilot-Staging-20241126-1844
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241126-1844
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241126-1844
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-2028</summary>
> >
> > #### fp-FrogPilot-Staging-20241126-2028
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241126-2028
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241126-2028
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-2059</summary>
> >
> > #### fp-FrogPilot-Staging-20241126-2059
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241126-2059
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241126-2059
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241126-2154</summary>
> >
> > #### fp-FrogPilot-Staging-20241126-2154
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241126-2154
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241126-2154
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241127-0817</summary>
> >
> > #### fp-FrogPilot-Staging-20241127-0817
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241127-0817
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241127-0817
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241127-2301</summary>
> >
> > #### fp-FrogPilot-Staging-20241127-2301
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241127-2301
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241127-2301
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241128-0802</summary>
> >
> > #### fp-FrogPilot-Staging-20241128-0802
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241128-0802
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241128-0802
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241128-0847</summary>
> >
> > #### fp-FrogPilot-Staging-20241128-0847
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241128-0847
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241128-0847
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241128-1138</summary>
> >
> > #### fp-FrogPilot-Staging-20241128-1138
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241128-1138
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241128-1138
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241128-1943</summary>
> >
> > #### fp-FrogPilot-Staging-20241128-1943
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241128-1943
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241128-1943
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241129-1239</summary>
> >
> > #### fp-FrogPilot-Staging-20241129-1239
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241129-1239
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241129-1239
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241129-1802</summary>
> >
> > #### fp-FrogPilot-Staging-20241129-1802
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241129-1802
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241129-1802
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241129-2053</summary>
> >
> > #### fp-FrogPilot-Staging-20241129-2053
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241129-2053
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241129-2053
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241130-1456</summary>
> >
> > #### fp-FrogPilot-Staging-20241130-1456
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241130-1456
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241130-1456
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241201-0526</summary>
> >
> > #### fp-FrogPilot-Staging-20241201-0526
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241201-0526
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241201-0526
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241202-0338</summary>
> >
> > #### fp-FrogPilot-Staging-20241202-0338
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241202-0338
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241202-0338
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241202-0446</summary>
> >
> > #### fp-FrogPilot-Staging-20241202-0446
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241202-0446
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241202-0446
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241202-0905</summary>
> >
> > #### fp-FrogPilot-Staging-20241202-0905
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241202-0905
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241202-0905
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241203-0719</summary>
> >
> > #### fp-FrogPilot-Staging-20241203-0719
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241203-0719
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241203-0719
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241203-1942</summary>
> >
> > #### fp-FrogPilot-Staging-20241203-1942
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241203-1942
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241203-1942
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241204-0856</summary>
> >
> > #### fp-FrogPilot-Staging-20241204-0856
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241204-0856
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241204-0856
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241205-0509</summary>
> >
> > #### fp-FrogPilot-Staging-20241205-0509
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241205-0509
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241205-0509
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241206-0506</summary>
> >
> > #### fp-FrogPilot-Staging-20241206-0506
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241206-0506
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241206-0506
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241206-1634</summary>
> >
> > #### fp-FrogPilot-Staging-20241206-1634
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241206-1634
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241206-1634
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241206-1652</summary>
> >
> > #### fp-FrogPilot-Staging-20241206-1652
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241206-1652
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241206-1652
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241207-0919</summary>
> >
> > #### fp-FrogPilot-Staging-20241207-0919
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241207-0919
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241207-0919
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241207-1112</summary>
> >
> > #### fp-FrogPilot-Staging-20241207-1112
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241207-1112
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241207-1112
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241208-1436</summary>
> >
> > #### fp-FrogPilot-Staging-20241208-1436
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241208-1436
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241208-1436
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241208-1438</summary>
> >
> > #### fp-FrogPilot-Staging-20241208-1438
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241208-1438
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241208-1438
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241208-2303</summary>
> >
> > #### fp-FrogPilot-Staging-20241208-2303
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241208-2303
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241208-2303
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241209-0141</summary>
> >
> > #### fp-FrogPilot-Staging-20241209-0141
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241209-0141
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241209-0141
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241209-0148</summary>
> >
> > #### fp-FrogPilot-Staging-20241209-0148
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241209-0148
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241209-0148
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241209-0158</summary>
> >
> > #### fp-FrogPilot-Staging-20241209-0158
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241209-0158
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241209-0158
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241210-1026</summary>
> >
> > #### fp-FrogPilot-Staging-20241210-1026
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241210-1026
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241210-1026
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241210-1150</summary>
> >
> > #### fp-FrogPilot-Staging-20241210-1150
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241210-1150
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241210-1150
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241210-1155</summary>
> >
> > #### fp-FrogPilot-Staging-20241210-1155
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241210-1155
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241210-1155
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241210-1932</summary>
> >
> > #### fp-FrogPilot-Staging-20241210-1932
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241210-1932
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241210-1932
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241213-0925</summary>
> >
> > #### fp-FrogPilot-Staging-20241213-0925
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241213-0925
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241213-0925
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241213-1903</summary>
> >
> > #### fp-FrogPilot-Staging-20241213-1903
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241213-1903
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241213-1903
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241213-1916</summary>
> >
> > #### fp-FrogPilot-Staging-20241213-1916
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241213-1916
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241213-1916
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241213-1920</summary>
> >
> > #### fp-FrogPilot-Staging-20241213-1920
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241213-1920
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241213-1920
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241213-2121</summary>
> >
> > #### fp-FrogPilot-Staging-20241213-2121
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241213-2121
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241213-2121
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241213-2232</summary>
> >
> > #### fp-FrogPilot-Staging-20241213-2232
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241213-2232
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241213-2232
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241213-2243</summary>
> >
> > #### fp-FrogPilot-Staging-20241213-2243
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241213-2243
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241213-2243
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241214-1056</summary>
> >
> > #### fp-FrogPilot-Staging-20241214-1056
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241214-1056
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241214-1056
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241215-0023</summary>
> >
> > #### fp-FrogPilot-Staging-20241215-0023
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241215-0023
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241215-0023
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241215-0051</summary>
> >
> > #### fp-FrogPilot-Staging-20241215-0051
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241215-0051
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241215-0051
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241215-0125</summary>
> >
> > #### fp-FrogPilot-Staging-20241215-0125
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241215-0125
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241215-0125
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241215-0301</summary>
> >
> > #### fp-FrogPilot-Staging-20241215-0301
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241215-0301
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241215-0301
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241220-1206</summary>
> >
> > #### fp-FrogPilot-Staging-20241220-1206
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241220-1206
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241220-1206
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241220-1209</summary>
> >
> > #### fp-FrogPilot-Staging-20241220-1209
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241220-1209
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241220-1209
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241220-1911</summary>
> >
> > #### fp-FrogPilot-Staging-20241220-1911
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241220-1911
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241220-1911
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241221-2131</summary>
> >
> > #### fp-FrogPilot-Staging-20241221-2131
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241221-2131
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241221-2131
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241221-2138</summary>
> >
> > #### fp-FrogPilot-Staging-20241221-2138
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241221-2138
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241221-2138
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241221-2238</summary>
> >
> > #### fp-FrogPilot-Staging-20241221-2238
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20241221-2238
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20241221-2238
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250102-0624</summary>
> >
> > #### fp-FrogPilot-Staging-20250102-0624
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250102-0624
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250102-0624
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250102-0659</summary>
> >
> > #### fp-FrogPilot-Staging-20250102-0659
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250102-0659
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250102-0659
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250113-1935</summary>
> >
> > #### fp-FrogPilot-Staging-20250113-1935
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250113-1935
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250113-1935
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250113-2021</summary>
> >
> > #### fp-FrogPilot-Staging-20250113-2021
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250113-2021
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250113-2021
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250113-2147</summary>
> >
> > #### fp-FrogPilot-Staging-20250113-2147
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250113-2147
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250113-2147
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250114-0048</summary>
> >
> > #### fp-FrogPilot-Staging-20250114-0048
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250114-0048
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250114-0048
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250115-1920</summary>
> >
> > #### fp-FrogPilot-Staging-20250115-1920
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250115-1920
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250115-1920
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250115-1931</summary>
> >
> > #### fp-FrogPilot-Staging-20250115-1931
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250115-1931
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250115-1931
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250115-1934</summary>
> >
> > #### fp-FrogPilot-Staging-20250115-1934
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250115-1934
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250115-1934
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250116-0430</summary>
> >
> > #### fp-FrogPilot-Staging-20250116-0430
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250116-0430
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250116-0430
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250117-0700</summary>
> >
> > #### fp-FrogPilot-Staging-20250117-0700
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250117-0700
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250117-0700
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250118-0834</summary>
> >
> > #### fp-FrogPilot-Staging-20250118-0834
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250118-0834
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250118-0834
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250125-2345</summary>
> >
> > #### fp-FrogPilot-Staging-20250125-2345
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250125-2345
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250125-2345
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250126-0228</summary>
> >
> > #### fp-FrogPilot-Staging-20250126-0228
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250126-0228
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250126-0228
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250126-0446</summary>
> >
> > #### fp-FrogPilot-Staging-20250126-0446
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250126-0446
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250126-0446
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250127-0330</summary>
> >
> > #### fp-FrogPilot-Staging-20250127-0330
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250127-0330
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250127-0330
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250127-0336</summary>
> >
> > #### fp-FrogPilot-Staging-20250127-0336
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250127-0336
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250127-0336
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250127-0933</summary>
> >
> > #### fp-FrogPilot-Staging-20250127-0933
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250127-0933
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250127-0933
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250127-2006</summary>
> >
> > #### fp-FrogPilot-Staging-20250127-2006
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250127-2006
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250127-2006
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-0754</summary>
> >
> > #### fp-FrogPilot-Staging-20250128-0754
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250128-0754
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250128-0754
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-0808</summary>
> >
> > #### fp-FrogPilot-Staging-20250128-0808
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250128-0808
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250128-0808
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250128-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250128-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250128-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250128-1952</summary>
> >
> > #### fp-FrogPilot-Staging-20250128-1952
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250128-1952
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250128-1952
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-0137</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-0137
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-0137
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-0137
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-0613</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-0613
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-0613
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-0613
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-0652</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-0652
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-0652
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-0652
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-2119</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-2119
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-2119
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-2119
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-2131</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-2131
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-2131
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-2131
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-2238</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-2238
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-2238
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-2238
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-2248</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-2248
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-2248
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-2248
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-2341</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-2341
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-2341
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-2341
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250202-2342</summary>
> >
> > #### fp-FrogPilot-Staging-20250202-2342
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250202-2342
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250202-2342
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-0133</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-0133
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-0133
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-0133
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-0735</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-0735
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-0735
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-0735
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-1020</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-1020
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-1020
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-1020
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-1104</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-1104
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-1104
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-1104
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-1110</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-1110
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-1110
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-1110
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-1122</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-1122
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-1122
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-1122
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-1126</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-1126
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-1126
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-1126
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250203-1147</summary>
> >
> > #### fp-FrogPilot-Staging-20250203-1147
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250203-1147
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250203-1147
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250204-0158</summary>
> >
> > #### fp-FrogPilot-Staging-20250204-0158
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250204-0158
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250204-0158
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250204-0511</summary>
> >
> > #### fp-FrogPilot-Staging-20250204-0511
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250204-0511
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250204-0511
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-0146</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-0146
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-0146
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-0146
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-0249</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-0249
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-0249
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-0249
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-0442</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-0442
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-0442
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-0442
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1822</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-1822
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-1822
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-1822
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1913</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-1913
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-1913
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-1913
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1938</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-1938
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-1938
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-1938
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-1953</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-1953
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-1953
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-1953
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-2009</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-2009
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-2009
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-2009
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250205-2221</summary>
> >
> > #### fp-FrogPilot-Staging-20250205-2221
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250205-2221
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250205-2221
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250207-0243</summary>
> >
> > #### fp-FrogPilot-Staging-20250207-0243
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250207-0243
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250207-0243
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250212-2329</summary>
> >
> > #### fp-FrogPilot-Staging-20250212-2329
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250212-2329
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250212-2329
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250213-1733</summary>
> >
> > #### fp-FrogPilot-Staging-20250213-1733
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250213-1733
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250213-1733
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250214-2038</summary>
> >
> > #### fp-FrogPilot-Staging-20250214-2038
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250214-2038
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250214-2038
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250219-0355</summary>
> >
> > #### fp-FrogPilot-Staging-20250219-0355
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250219-0355
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250219-0355
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250220-2101</summary>
> >
> > #### fp-FrogPilot-Staging-20250220-2101
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250220-2101
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250220-2101
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250221-1932</summary>
> >
> > #### fp-FrogPilot-Staging-20250221-1932
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250221-1932
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250221-1932
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250303-0341</summary>
> >
> > #### fp-FrogPilot-Staging-20250303-0341
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250303-0341
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250303-0341
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250303-0724</summary>
> >
> > #### fp-FrogPilot-Staging-20250303-0724
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250303-0724
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250303-0724
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250303-0734</summary>
> >
> > #### fp-FrogPilot-Staging-20250303-0734
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250303-0734
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250303-0734
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250303-0908</summary>
> >
> > #### fp-FrogPilot-Staging-20250303-0908
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250303-0908
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250303-0908
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250303-0924</summary>
> >
> > #### fp-FrogPilot-Staging-20250303-0924
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250303-0924
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250303-0924
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250305-2044</summary>
> >
> > #### fp-FrogPilot-Staging-20250305-2044
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250305-2044
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250305-2044
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250305-2209</summary>
> >
> > #### fp-FrogPilot-Staging-20250305-2209
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250305-2209
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250305-2209
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250306-1941</summary>
> >
> > #### fp-FrogPilot-Staging-20250306-1941
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250306-1941
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250306-1941
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250307-0616</summary>
> >
> > #### fp-FrogPilot-Staging-20250307-0616
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250307-0616
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250307-0616
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250307-1722</summary>
> >
> > #### fp-FrogPilot-Staging-20250307-1722
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250307-1722
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250307-1722
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250307-1752</summary>
> >
> > #### fp-FrogPilot-Staging-20250307-1752
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250307-1752
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250307-1752
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250308-1840</summary>
> >
> > #### fp-FrogPilot-Staging-20250308-1840
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250308-1840
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250308-1840
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250308-1849</summary>
> >
> > #### fp-FrogPilot-Staging-20250308-1849
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250308-1849
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250308-1849
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250313-0309</summary>
> >
> > #### fp-FrogPilot-Staging-20250313-0309
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250313-0309
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250313-0309
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250313-1936</summary>
> >
> > #### fp-FrogPilot-Staging-20250313-1936
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250313-1936
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250313-1936
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250313-2345</summary>
> >
> > #### fp-FrogPilot-Staging-20250313-2345
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250313-2345
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250313-2345
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250314-0029</summary>
> >
> > #### fp-FrogPilot-Staging-20250314-0029
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250314-0029
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250314-0029
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250314-2143</summary>
> >
> > #### fp-FrogPilot-Staging-20250314-2143
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250314-2143
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250314-2143
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250314-2146</summary>
> >
> > #### fp-FrogPilot-Staging-20250314-2146
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250314-2146
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250314-2146
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250317-1957</summary>
> >
> > #### fp-FrogPilot-Staging-20250317-1957
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250317-1957
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250317-1957
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250320-1944</summary>
> >
> > #### fp-FrogPilot-Staging-20250320-1944
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250320-1944
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250320-1944
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250321-0217</summary>
> >
> > #### fp-FrogPilot-Staging-20250321-0217
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250321-0217
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250321-0217
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250322-0454</summary>
> >
> > #### fp-FrogPilot-Staging-20250322-0454
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250322-0454
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250322-0454
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250322-1848</summary>
> >
> > #### fp-FrogPilot-Staging-20250322-1848
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250322-1848
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250322-1848
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250328-1908</summary>
> >
> > #### fp-FrogPilot-Staging-20250328-1908
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250328-1908
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250328-1908
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250329-1027</summary>
> >
> > #### fp-FrogPilot-Staging-20250329-1027
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250329-1027
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250329-1027
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250329-1044</summary>
> >
> > #### fp-FrogPilot-Staging-20250329-1044
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250329-1044
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250329-1044
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250329-1853</summary>
> >
> > #### fp-FrogPilot-Staging-20250329-1853
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250329-1853
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250329-1853
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250329-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250329-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250329-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250329-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2144</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2144
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2144
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2144
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2147</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2147
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2147
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2147
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2154</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2154
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2154
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2154
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2204</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2204
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2204
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2204
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2207</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2207
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2207
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2207
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2215</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2215
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2215
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2215
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2226</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2226
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2226
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2226
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2245</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2245
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2245
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2245
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250410-2258</summary>
> >
> > #### fp-FrogPilot-Staging-20250410-2258
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250410-2258
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250410-2258
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250411-0200</summary>
> >
> > #### fp-FrogPilot-Staging-20250411-0200
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250411-0200
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250411-0200
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-0001</summary>
> >
> > #### fp-FrogPilot-Staging-20250412-0001
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250412-0001
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250412-0001
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-0017</summary>
> >
> > #### fp-FrogPilot-Staging-20250412-0017
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250412-0017
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250412-0017
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-1221</summary>
> >
> > #### fp-FrogPilot-Staging-20250412-1221
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250412-1221
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250412-1221
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250412-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250412-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250412-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250412-2156</summary>
> >
> > #### fp-FrogPilot-Staging-20250412-2156
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250412-2156
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250412-2156
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250426-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250426-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250426-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250426-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250507-2137</summary>
> >
> > #### fp-FrogPilot-Staging-20250507-2137
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250507-2137
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250507-2137
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250615-2350</summary>
> >
> > #### fp-FrogPilot-Staging-20250615-2350
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250615-2350
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250615-2350
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250616-0306</summary>
> >
> > #### fp-FrogPilot-Staging-20250616-0306
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250616-0306
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250616-0306
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250616-0811</summary>
> >
> > #### fp-FrogPilot-Staging-20250616-0811
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250616-0811
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250616-0811
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250616-1005</summary>
> >
> > #### fp-FrogPilot-Staging-20250616-1005
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250616-1005
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250616-1005
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250617-0626</summary>
> >
> > #### fp-FrogPilot-Staging-20250617-0626
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250617-0626
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250617-0626
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-0119</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-0119
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-0119
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-0119
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-0134</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-0134
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-0134
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-0134
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-0756</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-0756
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-0756
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-0756
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-0953</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-0953
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-0953
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-0953
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-1015</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-1015
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-1015
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-1015
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-1041</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-1041
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-1041
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-1041
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-1048</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-1048
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-1048
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-1048
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250618-2046</summary>
> >
> > #### fp-FrogPilot-Staging-20250618-2046
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250618-2046
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250618-2046
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250619-0615</summary>
> >
> > #### fp-FrogPilot-Staging-20250619-0615
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250619-0615
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250619-0615
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250620-1231</summary>
> >
> > #### fp-FrogPilot-Staging-20250620-1231
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250620-1231
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250620-1231
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250620-2113</summary>
> >
> > #### fp-FrogPilot-Staging-20250620-2113
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250620-2113
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250620-2113
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250620-2332</summary>
> >
> > #### fp-FrogPilot-Staging-20250620-2332
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250620-2332
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250620-2332
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250621-0718</summary>
> >
> > #### fp-FrogPilot-Staging-20250621-0718
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250621-0718
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250621-0718
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250621-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250621-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250621-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250621-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250622-0354</summary>
> >
> > #### fp-FrogPilot-Staging-20250622-0354
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250622-0354
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250622-0354
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250622-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250622-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250622-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250622-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0004</summary>
> >
> > #### fp-FrogPilot-Staging-20250623-0004
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250623-0004
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250623-0004
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0052</summary>
> >
> > #### fp-FrogPilot-Staging-20250623-0052
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250623-0052
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250623-0052
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250623-0630</summary>
> >
> > #### fp-FrogPilot-Staging-20250623-0630
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250623-0630
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250623-0630
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250707-1055</summary>
> >
> > #### fp-FrogPilot-Staging-20250707-1055
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250707-1055
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250707-1055
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250707-1105</summary>
> >
> > #### fp-FrogPilot-Staging-20250707-1105
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250707-1105
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250707-1105
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250707-1155</summary>
> >
> > #### fp-FrogPilot-Staging-20250707-1155
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250707-1155
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250707-1155
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250708-1713</summary>
> >
> > #### fp-FrogPilot-Staging-20250708-1713
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250708-1713
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250708-1713
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250708-1729</summary>
> >
> > #### fp-FrogPilot-Staging-20250708-1729
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250708-1729
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250708-1729
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250708-1931</summary>
> >
> > #### fp-FrogPilot-Staging-20250708-1931
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250708-1931
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250708-1931
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250708-2056</summary>
> >
> > #### fp-FrogPilot-Staging-20250708-2056
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250708-2056
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250708-2056
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250708-2103</summary>
> >
> > #### fp-FrogPilot-Staging-20250708-2103
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250708-2103
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250708-2103
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250709-1445</summary>
> >
> > #### fp-FrogPilot-Staging-20250709-1445
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250709-1445
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250709-1445
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250709-1517</summary>
> >
> > #### fp-FrogPilot-Staging-20250709-1517
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250709-1517
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250709-1517
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250709-1714</summary>
> >
> > #### fp-FrogPilot-Staging-20250709-1714
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250709-1714
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250709-1714
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250709-1853</summary>
> >
> > #### fp-FrogPilot-Staging-20250709-1853
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250709-1853
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250709-1853
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250709-1910</summary>
> >
> > #### fp-FrogPilot-Staging-20250709-1910
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250709-1910
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250709-1910
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250711-1755</summary>
> >
> > #### fp-FrogPilot-Staging-20250711-1755
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250711-1755
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250711-1755
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250711-1849</summary>
> >
> > #### fp-FrogPilot-Staging-20250711-1849
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250711-1849
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250711-1849
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250712-1618</summary>
> >
> > #### fp-FrogPilot-Staging-20250712-1618
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250712-1618
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250712-1618
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250712-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250712-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250712-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250712-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250722-1103</summary>
> >
> > #### fp-FrogPilot-Staging-20250722-1103
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250722-1103
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250722-1103
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250722-2127</summary>
> >
> > #### fp-FrogPilot-Staging-20250722-2127
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250722-2127
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250722-2127
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250728-1100</summary>
> >
> > #### fp-FrogPilot-Staging-20250728-1100
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250728-1100
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250728-1100
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250728-1136</summary>
> >
> > #### fp-FrogPilot-Staging-20250728-1136
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250728-1136
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250728-1136
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250728-1854</summary>
> >
> > #### fp-FrogPilot-Staging-20250728-1854
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250728-1854
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250728-1854
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250731-0547</summary>
> >
> > #### fp-FrogPilot-Staging-20250731-0547
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250731-0547
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250731-0547
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250731-1540</summary>
> >
> > #### fp-FrogPilot-Staging-20250731-1540
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250731-1540
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250731-1540
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250802-1030</summary>
> >
> > #### fp-FrogPilot-Staging-20250802-1030
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250802-1030
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250802-1030
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250802-1049</summary>
> >
> > #### fp-FrogPilot-Staging-20250802-1049
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250802-1049
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250802-1049
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250802-1216</summary>
> >
> > #### fp-FrogPilot-Staging-20250802-1216
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250802-1216
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250802-1216
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250802-2207</summary>
> >
> > #### fp-FrogPilot-Staging-20250802-2207
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250802-2207
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250802-2207
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250802-2229</summary>
> >
> > #### fp-FrogPilot-Staging-20250802-2229
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250802-2229
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250802-2229
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250802-2359</summary>
> >
> > #### fp-FrogPilot-Staging-20250802-2359
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250802-2359
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250802-2359
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0000</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0000
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0000
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0000
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0014</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0014
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0014
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0014
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0029</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0029
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0029
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0029
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0040</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0040
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0040
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0040
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0306</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0306
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0306
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0306
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0330</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0330
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0330
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0330
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0344</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0344
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0344
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0344
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0849</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0849
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0849
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0849
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0857</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0857
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0857
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0857
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-0902</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-0902
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-0902
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-0902
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-1057</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-1057
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-1057
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-1057
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250803-2032</summary>
> >
> > #### fp-FrogPilot-Staging-20250803-2032
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250803-2032
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250803-2032
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250804-1706</summary>
> >
> > #### fp-FrogPilot-Staging-20250804-1706
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250804-1706
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250804-1706
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250804-1714</summary>
> >
> > #### fp-FrogPilot-Staging-20250804-1714
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250804-1714
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250804-1714
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250804-1815</summary>
> >
> > #### fp-FrogPilot-Staging-20250804-1815
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250804-1815
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250804-1815
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250805-0406</summary>
> >
> > #### fp-FrogPilot-Staging-20250805-0406
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250805-0406
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250805-0406
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250805-0722</summary>
> >
> > #### fp-FrogPilot-Staging-20250805-0722
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250805-0722
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250805-0722
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250805-2110</summary>
> >
> > #### fp-FrogPilot-Staging-20250805-2110
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250805-2110
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250805-2110
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250807-0712</summary>
> >
> > #### fp-FrogPilot-Staging-20250807-0712
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250807-0712
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250807-0712
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250809-0025</summary>
> >
> > #### fp-FrogPilot-Staging-20250809-0025
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250809-0025
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250809-0025
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250809-0035</summary>
> >
> > #### fp-FrogPilot-Staging-20250809-0035
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250809-0035
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250809-0035
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250809-0956</summary>
> >
> > #### fp-FrogPilot-Staging-20250809-0956
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250809-0956
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250809-0956
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250809-1051</summary>
> >
> > #### fp-FrogPilot-Staging-20250809-1051
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250809-1051
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250809-1051
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250809-1227</summary>
> >
> > #### fp-FrogPilot-Staging-20250809-1227
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250809-1227
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250809-1227
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250809-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250809-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250809-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250809-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250811-0123</summary>
> >
> > #### fp-FrogPilot-Staging-20250811-0123
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250811-0123
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250811-0123
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250818-2101</summary>
> >
> > #### fp-FrogPilot-Staging-20250818-2101
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250818-2101
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250818-2101
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250922-2014</summary>
> >
> > #### fp-FrogPilot-Staging-20250922-2014
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250922-2014
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250922-2014
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-0439</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-0439
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-0439
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-0439
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-0447</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-0447
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-0447
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-0447
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-0850</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-0850
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-0850
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-0850
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-1723</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-1723
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-1723
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-1723
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-1733</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-1733
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-1733
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-1733
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-1833</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-1833
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-1833
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-1833
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-1913</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-1913
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-1913
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-1913
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-1924</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-1924
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-1924
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-1924
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-1946</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-1946
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-1946
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-1946
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-1952</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-1952
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-1952
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-1952
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-2012</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-2012
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-2012
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-2012
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-2105</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-2105
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-2105
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-2105
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-2144</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-2144
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-2144
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-2144
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250923-2247</summary>
> >
> > #### fp-FrogPilot-Staging-20250923-2247
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250923-2247
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250923-2247
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250924-0454</summary>
> >
> > #### fp-FrogPilot-Staging-20250924-0454
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250924-0454
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250924-0454
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250924-0456</summary>
> >
> > #### fp-FrogPilot-Staging-20250924-0456
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250924-0456
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250924-0456
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250924-0653</summary>
> >
> > #### fp-FrogPilot-Staging-20250924-0653
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250924-0653
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250924-0653
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250924-1800</summary>
> >
> > #### fp-FrogPilot-Staging-20250924-1800
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250924-1800
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250924-1800
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250924-1927</summary>
> >
> > #### fp-FrogPilot-Staging-20250924-1927
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250924-1927
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250924-1927
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250925-0022</summary>
> >
> > #### fp-FrogPilot-Staging-20250925-0022
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250925-0022
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250925-0022
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250925-0603</summary>
> >
> > #### fp-FrogPilot-Staging-20250925-0603
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250925-0603
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250925-0603
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250925-0920</summary>
> >
> > #### fp-FrogPilot-Staging-20250925-0920
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250925-0920
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250925-0920
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250927-0405</summary>
> >
> > #### fp-FrogPilot-Staging-20250927-0405
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250927-0405
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250927-0405
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250927-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250927-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250927-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250927-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251015-2259</summary>
> >
> > #### fp-FrogPilot-Staging-20251015-2259
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251015-2259
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251015-2259
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251017-0459</summary>
> >
> > #### fp-FrogPilot-Staging-20251017-0459
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251017-0459
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251017-0459
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251018-0103</summary>
> >
> > #### fp-FrogPilot-Staging-20251018-0103
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251018-0103
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251018-0103
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251018-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20251018-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251018-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251018-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251023-1020</summary>
> >
> > #### fp-FrogPilot-Staging-20251023-1020
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251023-1020
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251023-1020
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251023-1030</summary>
> >
> > #### fp-FrogPilot-Staging-20251023-1030
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251023-1030
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251023-1030
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251023-1103</summary>
> >
> > #### fp-FrogPilot-Staging-20251023-1103
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251023-1103
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251023-1103
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251023-2226</summary>
> >
> > #### fp-FrogPilot-Staging-20251023-2226
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251023-2226
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251023-2226
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251024-2058</summary>
> >
> > #### fp-FrogPilot-Staging-20251024-2058
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251024-2058
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251024-2058
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251024-2107</summary>
> >
> > #### fp-FrogPilot-Staging-20251024-2107
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251024-2107
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251024-2107
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251024-2201</summary>
> >
> > #### fp-FrogPilot-Staging-20251024-2201
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251024-2201
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251024-2201
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251025-0656</summary>
> >
> > #### fp-FrogPilot-Staging-20251025-0656
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251025-0656
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251025-0656
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251025-0709</summary>
> >
> > #### fp-FrogPilot-Staging-20251025-0709
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251025-0709
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251025-0709
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251025-0733</summary>
> >
> > #### fp-FrogPilot-Staging-20251025-0733
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251025-0733
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251025-0733
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251025-0912</summary>
> >
> > #### fp-FrogPilot-Staging-20251025-0912
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251025-0912
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251025-0912
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251026-0249</summary>
> >
> > #### fp-FrogPilot-Staging-20251026-0249
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251026-0249
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251026-0249
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251026-0401</summary>
> >
> > #### fp-FrogPilot-Staging-20251026-0401
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251026-0401
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251026-0401
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251027-0647</summary>
> >
> > #### fp-FrogPilot-Staging-20251027-0647
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251027-0647
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251027-0647
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251027-0740</summary>
> >
> > #### fp-FrogPilot-Staging-20251027-0740
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251027-0740
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251027-0740
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251027-2224</summary>
> >
> > #### fp-FrogPilot-Staging-20251027-2224
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251027-2224
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251027-2224
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2000</summary>
> >
> > #### fp-FrogPilot-Staging-20251028-2000
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251028-2000
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251028-2000
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2018</summary>
> >
> > #### fp-FrogPilot-Staging-20251028-2018
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251028-2018
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251028-2018
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2019</summary>
> >
> > #### fp-FrogPilot-Staging-20251028-2019
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251028-2019
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251028-2019
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2111</summary>
> >
> > #### fp-FrogPilot-Staging-20251028-2111
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251028-2111
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251028-2111
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2218</summary>
> >
> > #### fp-FrogPilot-Staging-20251028-2218
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251028-2218
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251028-2218
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251028-2219</summary>
> >
> > #### fp-FrogPilot-Staging-20251028-2219
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251028-2219
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251028-2219
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251030-2305</summary>
> >
> > #### fp-FrogPilot-Staging-20251030-2305
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251030-2305
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251030-2305
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251031-0132</summary>
> >
> > #### fp-FrogPilot-Staging-20251031-0132
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251031-0132
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251031-0132
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251031-0756</summary>
> >
> > #### fp-FrogPilot-Staging-20251031-0756
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251031-0756
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251031-0756
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251031-0800</summary>
> >
> > #### fp-FrogPilot-Staging-20251031-0800
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251031-0800
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251031-0800
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251031-2023</summary>
> >
> > #### fp-FrogPilot-Staging-20251031-2023
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251031-2023
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251031-2023
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251031-2037</summary>
> >
> > #### fp-FrogPilot-Staging-20251031-2037
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251031-2037
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251031-2037
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251101-0259</summary>
> >
> > #### fp-FrogPilot-Staging-20251101-0259
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251101-0259
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251101-0259
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251101-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20251101-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251101-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251101-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251102-0455</summary>
> >
> > #### fp-FrogPilot-Staging-20251102-0455
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251102-0455
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251102-0455
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251102-0501</summary>
> >
> > #### fp-FrogPilot-Staging-20251102-0501
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251102-0501
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251102-0501
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251102-0512</summary>
> >
> > #### fp-FrogPilot-Staging-20251102-0512
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251102-0512
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251102-0512
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251102-0522</summary>
> >
> > #### fp-FrogPilot-Staging-20251102-0522
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251102-0522
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251102-0522
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251108-0119</summary>
> >
> > #### fp-FrogPilot-Staging-20251108-0119
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251108-0119
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251108-0119
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251108-0129</summary>
> >
> > #### fp-FrogPilot-Staging-20251108-0129
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251108-0129
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251108-0129
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251108-1330</summary>
> >
> > #### fp-FrogPilot-Staging-20251108-1330
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251108-1330
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251108-1330
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251109-0617</summary>
> >
> > #### fp-FrogPilot-Staging-20251109-0617
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251109-0617
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251109-0617
> > ```
> >
> > </details>
> >
>
> </details>



### [< Sunnypilot dev-c3 >](https://github.com/reopenpilot/openpilot-archive/commits/sp-dev-c3-20250902-1405/)
```
https://smiskol.com/fork/sp/dev-c3
```
```
curl -fsSL https://bit.ly/reopenpilot | bash -s 'sp/dev-c3'
```

> <details><summary>Show older versions</summary>
>
> <br>
> 
> 
> > <details><summary>20240729-2010</summary>
> >
> > #### sp-dev-c3-20240729-2010
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240729-2010
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240729-2010
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240730-0131</summary>
> >
> > #### sp-dev-c3-20240730-0131
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240730-0131
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240730-0131
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-0424</summary>
> >
> > #### sp-dev-c3-20240731-0424
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240731-0424
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240731-0424
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-2209</summary>
> >
> > #### sp-dev-c3-20240731-2209
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240731-2209
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240731-2209
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-2305</summary>
> >
> > #### sp-dev-c3-20240731-2305
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240731-2305
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240731-2305
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240731-2358</summary>
> >
> > #### sp-dev-c3-20240731-2358
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240731-2358
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240731-2358
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-0051</summary>
> >
> > #### sp-dev-c3-20240801-0051
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240801-0051
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240801-0051
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-1041</summary>
> >
> > #### sp-dev-c3-20240801-1041
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240801-1041
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240801-1041
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-1058</summary>
> >
> > #### sp-dev-c3-20240801-1058
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240801-1058
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240801-1058
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-1353</summary>
> >
> > #### sp-dev-c3-20240801-1353
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240801-1353
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240801-1353
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240801-1512</summary>
> >
> > #### sp-dev-c3-20240801-1512
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240801-1512
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240801-1512
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1535</summary>
> >
> > #### sp-dev-c3-20240802-1535
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240802-1535
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240802-1535
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-1650</summary>
> >
> > #### sp-dev-c3-20240803-1650
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240803-1650
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240803-1650
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-2114</summary>
> >
> > #### sp-dev-c3-20240803-2114
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240803-2114
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240803-2114
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-0204</summary>
> >
> > #### sp-dev-c3-20240804-0204
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240804-0204
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240804-0204
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-1139</summary>
> >
> > #### sp-dev-c3-20240804-1139
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240804-1139
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240804-1139
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-1201</summary>
> >
> > #### sp-dev-c3-20240804-1201
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240804-1201
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240804-1201
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-1321</summary>
> >
> > #### sp-dev-c3-20240804-1321
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240804-1321
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240804-1321
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-1527</summary>
> >
> > #### sp-dev-c3-20240804-1527
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240804-1527
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240804-1527
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-1616</summary>
> >
> > #### sp-dev-c3-20240804-1616
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240804-1616
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240804-1616
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-2142</summary>
> >
> > #### sp-dev-c3-20240804-2142
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240804-2142
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240804-2142
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240805-2243</summary>
> >
> > #### sp-dev-c3-20240805-2243
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240805-2243
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240805-2243
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240805-2348</summary>
> >
> > #### sp-dev-c3-20240805-2348
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240805-2348
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240805-2348
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240806-0301</summary>
> >
> > #### sp-dev-c3-20240806-0301
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240806-0301
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240806-0301
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240806-0514</summary>
> >
> > #### sp-dev-c3-20240806-0514
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240806-0514
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240806-0514
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240806-2304</summary>
> >
> > #### sp-dev-c3-20240806-2304
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240806-2304
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240806-2304
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-0411</summary>
> >
> > #### sp-dev-c3-20240807-0411
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240807-0411
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240807-0411
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-1113</summary>
> >
> > #### sp-dev-c3-20240807-1113
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240807-1113
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240807-1113
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-1129</summary>
> >
> > #### sp-dev-c3-20240807-1129
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240807-1129
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240807-1129
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-1148</summary>
> >
> > #### sp-dev-c3-20240807-1148
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240807-1148
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240807-1148
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-1502</summary>
> >
> > #### sp-dev-c3-20240807-1502
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240807-1502
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240807-1502
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-1538</summary>
> >
> > #### sp-dev-c3-20240807-1538
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240807-1538
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240807-1538
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240807-1756</summary>
> >
> > #### sp-dev-c3-20240807-1756
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240807-1756
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240807-1756
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240809-0138</summary>
> >
> > #### sp-dev-c3-20240809-0138
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240809-0138
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240809-0138
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-0109</summary>
> >
> > #### sp-dev-c3-20240810-0109
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-0109
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-0109
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-1518</summary>
> >
> > #### sp-dev-c3-20240810-1518
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-1518
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-1518
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-1703</summary>
> >
> > #### sp-dev-c3-20240810-1703
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-1703
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-1703
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-1828</summary>
> >
> > #### sp-dev-c3-20240810-1828
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-1828
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-1828
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-1846</summary>
> >
> > #### sp-dev-c3-20240810-1846
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-1846
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-1846
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-1856</summary>
> >
> > #### sp-dev-c3-20240810-1856
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-1856
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-1856
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-1914</summary>
> >
> > #### sp-dev-c3-20240810-1914
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-1914
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-1914
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240810-2108</summary>
> >
> > #### sp-dev-c3-20240810-2108
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240810-2108
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240810-2108
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240811-0151</summary>
> >
> > #### sp-dev-c3-20240811-0151
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240811-0151
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240811-0151
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240811-0509</summary>
> >
> > #### sp-dev-c3-20240811-0509
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240811-0509
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240811-0509
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240812-0414</summary>
> >
> > #### sp-dev-c3-20240812-0414
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240812-0414
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240812-0414
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240812-1959</summary>
> >
> > #### sp-dev-c3-20240812-1959
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240812-1959
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240812-1959
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240813-0516</summary>
> >
> > #### sp-dev-c3-20240813-0516
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240813-0516
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240813-0516
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240813-0706</summary>
> >
> > #### sp-dev-c3-20240813-0706
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240813-0706
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240813-0706
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240813-1923</summary>
> >
> > #### sp-dev-c3-20240813-1923
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240813-1923
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240813-1923
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240820-0622</summary>
> >
> > #### sp-dev-c3-20240820-0622
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240820-0622
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240820-0622
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240827-0341</summary>
> >
> > #### sp-dev-c3-20240827-0341
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240827-0341
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240827-0341
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240930-0039</summary>
> >
> > #### sp-dev-c3-20240930-0039
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20240930-0039
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20240930-0039
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241027-0823</summary>
> >
> > #### sp-dev-c3-20241027-0823
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20241027-0823
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20241027-0823
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20241116-1913</summary>
> >
> > #### sp-dev-c3-20241116-1913
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20241116-1913
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20241116-1913
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250318-1710</summary>
> >
> > #### sp-dev-c3-20250318-1710
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20250318-1710
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20250318-1710
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250902-1405</summary>
> >
> > #### sp-dev-c3-20250902-1405
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-dev-c3-20250902-1405
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-dev-c3-20250902-1405
> > ```
> >
> > </details>
> >
>
> </details>


### [< Sunnypilot staging-c3 >](https://github.com/reopenpilot/openpilot-archive/commits/sp-staging-c3-20250318-1711/)
```
https://smiskol.com/fork/sp/staging-c3
```
```
curl -fsSL https://bit.ly/reopenpilot | bash -s 'sp/staging-c3'
```

> <details><summary>Show older versions</summary>
>
> <br>
> 
> 
> > <details><summary>20240729-1909</summary>
> >
> > #### sp-staging-c3-20240729-1909
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240729-1909
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240729-1909
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240730-1547</summary>
> >
> > #### sp-staging-c3-20240730-1547
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240730-1547
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240730-1547
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-0250</summary>
> >
> > #### sp-staging-c3-20240802-0250
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-0250
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-0250
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-0331</summary>
> >
> > #### sp-staging-c3-20240802-0331
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-0331
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-0331
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-0342</summary>
> >
> > #### sp-staging-c3-20240802-0342
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-0342
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-0342
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1041</summary>
> >
> > #### sp-staging-c3-20240802-1041
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-1041
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-1041
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1434</summary>
> >
> > #### sp-staging-c3-20240802-1434
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-1434
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-1434
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1443</summary>
> >
> > #### sp-staging-c3-20240802-1443
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-1443
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-1443
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1546</summary>
> >
> > #### sp-staging-c3-20240802-1546
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-1546
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-1546
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1550</summary>
> >
> > #### sp-staging-c3-20240802-1550
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-1550
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-1550
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1643</summary>
> >
> > #### sp-staging-c3-20240802-1643
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-1643
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-1643
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240802-1647</summary>
> >
> > #### sp-staging-c3-20240802-1647
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240802-1647
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240802-1647
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240803-1421</summary>
> >
> > #### sp-staging-c3-20240803-1421
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240803-1421
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240803-1421
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-0147</summary>
> >
> > #### sp-staging-c3-20240804-0147
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240804-0147
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240804-0147
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-0153</summary>
> >
> > #### sp-staging-c3-20240804-0153
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240804-0153
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240804-0153
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-1133</summary>
> >
> > #### sp-staging-c3-20240804-1133
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240804-1133
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240804-1133
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240804-1621</summary>
> >
> > #### sp-staging-c3-20240804-1621
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240804-1621
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240804-1621
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240812-0343</summary>
> >
> > #### sp-staging-c3-20240812-0343
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240812-0343
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240812-0343
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240812-0348</summary>
> >
> > #### sp-staging-c3-20240812-0348
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240812-0348
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240812-0348
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240813-2008</summary>
> >
> > #### sp-staging-c3-20240813-2008
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240813-2008
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240813-2008
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240813-2024</summary>
> >
> > #### sp-staging-c3-20240813-2024
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240813-2024
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240813-2024
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240813-2029</summary>
> >
> > #### sp-staging-c3-20240813-2029
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240813-2029
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240813-2029
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20240815-1001</summary>
> >
> > #### sp-staging-c3-20240815-1001
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20240815-1001
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20240815-1001
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20250318-1711</summary>
> >
> > #### sp-staging-c3-20250318-1711
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/sp-staging-c3-20250318-1711
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s sp-staging-c3-20250318-1711
> > ```
> >
> > </details>
> >
>
> </details>
