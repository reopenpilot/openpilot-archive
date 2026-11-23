<div align="center" style="text-align: center;">

<h1>FrogPilot 🐸</h1>

[![Ask FrogBot](https://img.shields.io/badge/Ask-FrogBot-green)](https://frogpilot.com/frogbot/)
[![Blog](https://img.shields.io/badge/Blog-FrogPilot-green)](https://frogpilot.com/blog/)
[![Discord](https://img.shields.io/discord/1137853399715549214?label=Discord)](https://discord.frogpilot.com)
[![Last Updated](https://img.shields.io/badge/Last%20Updated-October%2031st%2C%202026-brightgreen)](https://github.com/FrogAi/FrogPilot/releases/latest)
[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](LICENSE)
[![Wiki](https://img.shields.io/badge/Wiki-FrogPilot-blue?logo=wiki)](https://frogpilot.com/wiki/)

<a href="https://frogpilot.com"><img src="https://frogpilot.com/images/frogpilot-share-card.png" alt="FrogPilot, with the line “We may have gotten carried away with the frogs.” Its frog mascot stands beside a car with a FrogPilot license plate" width="800"></a>

</div>

**FrogPilot** is a bleeding-edge, highly customizable fork of [openpilot](#new-to-openpilot) for comma devices. It packs advanced features and cutting-edge experiments that often arrive long before official releases, and lets you tune how your car brakes, looks, sounds, speeds up, and steers. As a highly experimental and unofficial version of openpilot, **FrogPilot** should *always* be used with caution!

<a id="new-to-openpilot"></a>

What is openpilot?
------

**openpilot** is free, open-source driver assistance software made by [comma](https://comma.ai) ([docs](https://docs.comma.ai)). It runs on a **comma device**, which mounts on your windshield and connects to your car through a **car harness**.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-how-it-works-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-how-it-works-medium.svg"><img src="https://frogpilot.com/images/frogpilot-how-it-works.svg" alt="A side view of a car with a small gadget, the comma device, mounted on the inside of the windshield near the rearview mirror. Its road cameras look forward and see lanes, cars, curves, stop signs, and stop lights, and its driver camera looks back at the driver and checks you're paying attention. A short cable runs up from the device to the car harness, which plugs in behind the rearview mirror at the top of the windshield and brings in your car's data, such as its speed, and radar on some cars. A dotted line leads to a box showing what is inside the comma device, where it runs openpilot, comma's driving software, with FrogPilot's changes, features, and settings on top. Through the car harness, your car steers and, on many cars, speeds up, brakes, and stops for red lights and stop signs. If you stop paying attention, it issues an urgent takeover warning." width="800"></picture></p>

On [308+ supported cars](docs/CARS.md), it steers to keep you centered in your lane and, on many of them, manages your following distance and speed, while you stay alert and ready to take over.

**FrogPilot** is a *fork* of openpilot, meaning it's based on comma's openpilot and adds its own features and settings on top. It installs the same way and runs on the **comma 3** and **comma 3X**.

See openpilot in action:

<table>
  <tr>
    <td><a href="https://youtu.be/NmBfgOanCyk" title="Video By Greer Viau"><img src="https://github.com/commaai/openpilot/assets/8762862/2f7112ae-f748-4f39-b617-fabd689c3772"></a></td>
    <td><a href="https://youtu.be/VHKyqZ7t8Gw" title="Video By Logan LeGrand"><img src="https://github.com/commaai/openpilot/assets/8762862/92351544-2833-40d7-9e0b-7ef7ae37ec4c"></a></td>
    <td><a href="https://youtu.be/SUIZYzxtMQs" title="A drive to Taco Bell"><img src="https://github.com/commaai/openpilot/assets/8762862/05ceefc5-2628-439c-a9b2-89ce77dc6f63"></a></td>
  </tr>
</table>

✨ What FrogPilot adds
------

Your comma device's **Settings → FrogPilot** menu holds these features and their options. **Tuning Level**, in that menu, controls how many settings you see, from **Minimal** through **Standard** and **Advanced** to **Developer**. The descriptions below note when a setting needs a higher tuning level or a supported car.

In the menu paths, **Manage** is the button beside the preceding setting. If the button is disabled, turn that setting on first. The **Gas / Brake** panel only appears when openpilot controls your car's gas and brake.

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-human-like-driving.svg" width="36" height="36" align="absmiddle" alt=""></picture> Acceleration and Deceleration Profiles

In **"Chill Mode"**, acceleration and deceleration profiles let you choose how briskly your car speeds up and how firmly it slows down.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-acceleration-profiles-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-acceleration-profiles-medium.svg"><img src="https://frogpilot.com/images/frogpilot-acceleration-profiles.svg" alt="Two panels compare FrogPilot's Acceleration Profile and Deceleration Profile choices. The left panel is a line graph of speed in mph over the first 15 seconds of speeding up from a stop. Sport+ is as quick as your car allows and reaches about 67 mph, Sport (the default) reaches about 51 mph, Standard about 41 mph, and Eco about 35 mph. This calculated example caps acceleration at 2.0 m/s². Actual acceleration varies by car. The right panel shows the hardest FrogPilot brakes with nobody ahead. Standard uses full braking, Eco (the default) brakes half as hard, and Eco+ just coasts. Full braking returns for traffic, curves, or required stops." width="800"></picture></p>

**"Acceleration Profile"** sets how briskly it speeds up, with **"Eco"**, **"Standard"**, **"Sport"** (the default), and **"Sport+"** to choose from. Each profile sets an upper limit on acceleration, but your car may accelerate more slowly. **"Eco"** keeps this limit below **"Standard"** at every speed.

**"Deceleration Profile"** starts out on **"Eco"**, so with no car ahead it brakes at most half as hard as stock openpilot and slows gently for a lower set speed or speed limit. Switch it to **"Eco+"** and it just lets off the gas and coasts. Full braking returns for traffic, curves, or required stops. These profile limits do not apply in **"Experimental Mode"**, including when **"Conditional Experimental Mode"** switches it on.

Adjust these settings under **FrogPilot → Driving Controls → Gas / Brake → Longitudinal Tuning → Manage**. **"Acceleration Profile"** is available at every tuning level, while **"Deceleration Profile"** requires the **Advanced** or **Developer** tuning level.

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-always-on-lateral.svg" width="36" height="36" align="absmiddle" alt=""></picture> Always On Lateral (AOL)

On stock openpilot, canceling cruise or tapping the brake turns everything off, steering included, often right when you're slowing for a tight bend or traffic. With **"Always On Lateral"**, **FrogPilot** keeps steering for you the whole time your car's cruise control is switched on\*.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-always-on-lateral-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-always-on-lateral-medium.svg"><img src="https://frogpilot.com/images/frogpilot-always-on-lateral.svg" alt="On stock openpilot, tapping the brake turns off both steering and speed control until you resume cruise. With FrogPilot's Always On Lateral, tapping the brake turns off only speed control. Steering stays on, and resuming cruise brings speed control back." width="800"></picture></p>

Press cancel, tap the brake, or work the pedals yourself, and it keeps holding your lane. Resuming cruise brings speed control back. Whether you're easing off for a curve, tapping the brake to let someone merge, or crawling through stop-and-go traffic, the steering stays on, so you can stay relaxed instead of grabbing the wheel.

It's on by default. You can change it under **FrogPilot → Driving Controls → Steering → Always On Lateral**. To customize its behavior, choose the **Standard** tuning level or higher and tap **Manage** beside the toggle.

\*On newer Genesis, Hyundai, and Kia cars that use the car's own cruise control and have a lane-keeping (LKAS) button on the steering wheel, that button or engaging openpilot turns it on instead of cruise control.

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-conditional-experimental-mode.svg" width="36" height="36" align="absmiddle" alt=""></picture> Conditional Experimental Mode (CEM)

**"Conditional Experimental Mode"** switches between openpilot's two driving modes for you. It cruises in **"Chill Mode"** and hands over to **"Experimental Mode"** only while one of its triggers applies.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-conditional-experimental-mode-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-conditional-experimental-mode-medium.svg"><img src="https://frogpilot.com/images/frogpilot-conditional-experimental-mode.svg" alt="How Conditional Experimental Mode works. FrogPilot watches six things and checks each one. For curves ahead, it checks whether a curve is detected. For low speeds, whether you're driving below a speed you choose. For slower or stopped cars ahead, whether a slower or stopped car is detected. For stop signs and stop lights, whether a stop sign or stop light is detected. For turns, whether your turn signal is on below a speed you choose. For unknown speed limits, whether no speed limit is found. If any one is true, it uses Experimental Mode, where the driving model picks the speed, slows for curves and turns, stops at red lights and stop signs, and never goes above your set speed. If none are true, it uses Chill Mode, which holds your set speed and follows the car ahead." width="800"></picture></p>

**"Chill Mode"** is predictable and smooth for steady cruising. **["Experimental Mode"](https://blog.comma.ai/090release/#experimental-mode)** lets the driving model pick the speed itself, so it slows for curves and stops for red lights and stop signs, but it's less predictable on the open road. On stock openpilot, you switch between them by hand.

Out of the box, it hands over for stop signs, stop lights, and turns, including the turns on your route while **"Navigate on openpilot"** is guiding you. To choose its triggers, open **FrogPilot → Driving Controls → Gas / Brake → Conditional Experimental Mode → Manage** with your tuning level set to **Standard** or higher. The **Advanced** and **Developer** tuning levels show additional trigger settings. The unknown-speed-limit trigger is set separately under **FrogPilot → Driving Controls → Gas / Brake → Speed Limit Controller → Manage → Fallback Speed → Experimental Mode**.

Once no trigger applies, it drops back to **"Chill Mode"**. You get the calm of **"Chill Mode"** on the highway and the stop-for-lights smarts of **"Experimental Mode"** around town, with no button presses.

**Stay attentive. "Experimental Mode" is an alpha feature, and mistakes are expected!**

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-curve-speed-controller.svg" width="36" height="36" align="absmiddle" alt=""></picture> Curve Speed Controller

In **"Chill Mode"**, stock openpilot doesn't slow down for curves ahead. **FrogPilot**'s **"Curve Speed Controller"** sees curves coming and slows down on its own, early and smoothly, so you're not braking hard into an off-ramp or a twisty back road.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-curve-speed-profiles-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-curve-speed-profiles-medium.svg"><img src="https://frogpilot.com/images/frogpilot-curve-speed-profiles.svg" alt="Line graph of speed through a curve in mph (0 to 80) against curve tightness, from tighter curves on the left to wider curves on the right, for FrogPilot's four Curve Speed Profiles. Sport is a red dashed line along the top that goes up to what your car's steering allows. Standard is a solid green line, a little brisker than Gentle. Gentle is a dotted blue line just below Standard, at a calm, unhurried pace. Adaptive, the default, is a light purple band with a purple edge, from below Gentle up to the Sport line. It starts like Standard and learns your pace from curves you drive yourself. For example, on a tight back-road bend, Gentle is 13 mph, Standard is 14, and Sport is up to 17. On a highway ramp, Gentle is 30, Standard is 32, and Sport is up to 39. On a sweeping highway bend, Gentle is 59, Standard is 63, and Sport is up to 77. It never goes above your set speed or past what your car's steering allows." width="800"></picture></p>

**"Adaptive"**, the default, starts like **"Standard"** and learns your pace from the curves you take yourself with cruise control off. **"Gentle"** takes curves at a calm, unhurried pace, **"Standard"** is a little brisker, and **"Sport"** goes up to what your car's steering allows. None goes above your set speed or past what your car's steering allows.

Turn it on under **FrogPilot → Driving Controls → Gas / Brake → Curve Speed Controller** with your tuning level set to **Standard** or higher. To choose a different **"Curve Speed Profile"**, set your tuning level to **Advanced** or **Developer**, then tap **Manage** beside **"Curve Speed Controller"**.

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-driving-personalities.svg" width="36" height="36" align="absmiddle" alt=""></picture> Driving Personalities

Stock openpilot's **"Aggressive"**, **"Standard"**, and **"Relaxed"** profiles are fixed. Switch on **"Driving Personalities"** to tune how much space each one leaves behind the car ahead, so **"Aggressive"** keeps up with traffic the way you like and **"Relaxed"** really feels relaxed.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-following-distance-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-following-distance-medium.svg"><img src="https://frogpilot.com/images/frogpilot-following-distance.svg" alt="Three road lanes, one for each driving personality, show the default gap behind a car going 65 mph, drawn to scale. Aggressive leaves 1.25 s, about 139 ft. Standard leaves 1.45 s, about 158 ft. Relaxed leaves 1.75 s, about 187 ft. The gap is seconds × your speed + about 20 ft. For Standard at 65 mph (95 ft/s), 1.45 s × 95 ft/s + 20 ft ≈ 158 ft." width="800"></picture></p>

With the default settings at 65 mph, **"Aggressive"** leaves the least room, **"Standard"** a little more, and **"Relaxed"** the most. Following distance is measured in seconds, so the gap grows as you go faster.

You can also tune how smoothly each one brakes and speeds up. With the default button assignment, you switch profiles with a tap of the following distance button on your steering wheel. On GM cars with adaptive cruise, the first tap opens the menu. Tap again within 3.5 seconds to change the profile.

To adjust a profile, set your tuning level to **Advanced** or **Developer**, then open **FrogPilot → Driving Controls → Gas / Brake → Driving Personalities → Manage** and tap **Manage** beside **Aggressive**, **Standard**, or **Relaxed**. **Following Distance** is available at both the **Advanced** and **Developer** tuning levels. The other five settings below require **Developer**. Each profile has its own values. The percentages use stock openpilot's **"Standard"** profile as the 100% reference. For the smoothness and response ones, a higher value feels gentler and a lower one quicker but more abrupt.

| Setting | Range | What it changes |
|---------|-------|-----------------|
| **Acceleration Smoothness** | 25–200% | How quickly it adjusts its acceleration while speeding up or holding speed |
| **Braking Smoothness** | 25–200% | How quickly it adjusts its braking while slowing down |
| **Following Distance** | 1.00–3.00 seconds | How much room it leaves behind the car ahead. It's measured in seconds, so the gap grows as you go faster |
| **Safety Gap Bias** | 25–200% | How strongly it avoids getting too close to the car ahead. Higher means it brakes earlier and more firmly to keep its space |
| **Slowdown Response** | 25–200% | How gradually it eases into and out of slowing down |
| **Speed-Up Response** | 25–200% | How gradually it eases into and out of speeding up |

Stuck in stop-and-go? Hold the following distance button for 2.5 seconds to turn on **"Traffic Mode"**, which keeps tighter gaps and reacts sooner, so you're not leaving room for every car to cut in. Tighter gaps mean less cushion, so stay ready to brake.

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-extra-alerts.svg" width="36" height="36" align="absmiddle" alt=""></picture> FrogPilot Alerts

Some moments are easy to miss. **"FrogPilot Alerts"** adds chimes stock openpilot doesn't have, plus a louder version of one it does.

**"Green Light Alert"** works when you're stopped at a light with no car ahead.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-alert-green-light-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-alert-green-light-medium.svg"><img src="https://frogpilot.com/images/frogpilot-alert-green-light.svg" alt="A stretch of road seen from above with your car stopped at the left and facing right, at a stop line with a traffic light, and there is no car ahead. A dashed arrow runs down the empty road with the words: the driving model predicts it's time to move. Under your car a yellow box says FrogPilot chimes, followed by the words: while your car is still stopped. Two notes at the bottom say: Green Light Alert may chime before the light changes. Check the light and road before moving." width="800"></picture></p>

It chimes when the driving model predicts it's time to move, rather than reading the light's color, so it may chime before the light changes.

**"Lead Departing Alert"** chimes after the car in front of you pulls away.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-alert-lead-departing-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-alert-lead-departing-medium.svg"><img src="https://frogpilot.com/images/frogpilot-alert-lead-departing.svg" alt="A stretch of road seen from above with your car stopped at the left and facing right, behind another car. The car ahead has only just started to move: it sits a little ahead of a dashed outline that marks where it was stopped, and an arrow runs down the road in front of it with the words: the car ahead starts to pull away. Under your car a yellow box says FrogPilot chimes, followed by the words: while your car is still stopped." width="800"></picture></p>

It chimes while you're still stopped. Treat both of these as a nudge to check the light and road before moving.

**"Louder Blind Spot Alert"** isn't a new alert.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-alert-blind-spot-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-alert-blind-spot-medium.svg"><img src="https://frogpilot.com/images/frogpilot-alert-blind-spot.svg" alt="A two-lane road seen from above with traffic heading right. Your car is in the top lane with its right turn signal blinking, and a dashed arrow curves from its front down into the bottom lane, with the words: you signal for a lane change while openpilot is steering. In the bottom lane another car sits beside your car and slightly behind it, with the words: a car is beside you, in your blind spot. Below the road a gray box says quiet prompt chime, and an arrow leads to a yellow box that says louder warning chime, followed by the words: only the chime changes. Two notes at the bottom say: openpilot already alerts you with Car Detected in Blindspot; this only swaps in the louder chime. Needs Lane Changes on, at least your Minimum Lane Change Speed, and a car with blind-spot monitoring." width="800"></picture></p>

openpilot already chimes "Car Detected in Blindspot" when you signal for a lane change while it's steering and a car is beside you; this swaps that quiet chime for openpilot's louder warning chime. It needs a car with blind-spot monitoring, **"Lane Changes"** turned on, and at least your **"Minimum Lane Change Speed"**.

**"Speed Limit Changed Alert"** chimes whenever the speed limit FrogPilot is reading changes, such as entering a school zone or coming off the highway.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-alert-speed-limit-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-alert-speed-limit-medium.svg"><img src="https://frogpilot.com/images/frogpilot-alert-speed-limit.svg" alt="A stretch of road seen from above with your car driving to the right. Behind it stands a 45 mph speed limit sign; just ahead of it a 25 mph sign stands at a dashed line across the road where the limit changes. An arrow runs down the road from that line with the words: the speed limit openpilot reads changes. Above the far end of the road are the words: for example, entering a school zone. Under your car a yellow box says FrogPilot chimes, followed by the words: right as the limit changes. A note at the bottom says: the limit comes from your dashboard, downloaded maps, signs the camera reads, or Mapbox, depending on your setup." width="800"></picture></p>

It appears when **"Show Speed Limits"** or **"Speed Limit Filler"** is on, or when **"Speed Limit Controller"** is on and openpilot controls the gas and brake.

Turn them on under **FrogPilot → Alerts and Sounds → Manage → FrogPilot Alerts → Manage**.

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-human-like-driving.svg" width="36" height="36" align="absmiddle" alt=""></picture> Human-Like Driving

**FrogPilot** works the gas and brake more like a careful driver, out of the box. The comparisons below are simulations run with the real openpilot and FrogPilot code.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-human-like-following-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-human-like-following-medium.svg"><img src="https://frogpilot.com/images/frogpilot-human-like-following.svg" alt="Two line graphs of your speed compare FrogPilot's Human-Like Following with stock openpilot in simulations run with the real code. When the car ahead slows down, FrogPilot eases off early and brakes 22% softer, keeping 67 ft of room after 20 seconds against stock openpilot's 48 ft. When the car ahead pulls away from a stop, FrogPilot sets off right away and gets moving 1.3 seconds sooner, ending 63 ft behind after 10 seconds against stock openpilot's 90 ft." width="800"></picture></p>

With **"Human-Like Following"**, **FrogPilot** plans around where the driving model expects the car ahead to go, so when traffic starts to slow, it lets off the gas sooner and brakes more gently. In these simulated comparisons, FrogPilot's hardest braking is 22% softer than stock openpilot's, and it gets moving 1.3 seconds sooner when the car ahead pulls away from a stop.

After 20 seconds in the braking comparison, FrogPilot has 67 ft of room to the car ahead and stock openpilot has 48 ft. After 10 seconds in the pull-away comparison, FrogPilot is 63 ft behind and stock openpilot is 90 ft behind.

In **"Chill Mode"**, **"Human-Like Acceleration"** eases into your set speed instead of rushing up to it.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-human-like-acceleration-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-human-like-acceleration-medium.svg"><img src="https://frogpilot.com/images/frogpilot-human-like-acceleration.svg" alt="A line graph of your speed pulling away from a stop on a slow street, set to 20 mph, from simulations run with the real code. Stock openpilot uses the same push at any set speed. FrogPilot's Human-Like Acceleration pulls away more gently, with its hardest push 19% softer. The lower your set speed, the gentler it pulls away, and on highways it uses full power." width="800"></picture></p>

The lower your set speed, the gentler it pulls away. In the simulation with nobody ahead and a set speed of 20 mph, FrogPilot's hardest push is 19% softer than stock openpilot's. On cars with a fixed launch push, it also replaces that push with openpilot's planned acceleration in either driving mode.

Adjust **"Human-Like Acceleration"** and **"Human-Like Following"** under **FrogPilot → Driving Controls → Gas / Brake → Longitudinal Tuning → Manage** with your tuning level set to **Advanced** or **Developer**.

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-model-manager.svg" width="36" height="36" align="absmiddle" alt=""></picture> Model Manager

The driving model is the AI at the heart of openpilot. It decides how to slow down, speed up, and steer, so it shapes how every drive feels.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-model-manager-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-model-manager-medium.svg"><img src="https://frogpilot.com/images/frogpilot-model-manager.svg" alt="Two rows, each with a label at the left. Stock openpilot has a single driving model, comma's model: one model, the one comma ships with each release. Model Manager has a range of models: Model A, highlighted as selected, Model B, Model C, and a new model that downloads on its own; you download the ones you want and switch with Select Driving Model. The model names are stand-ins, not real models." width="800"></picture></p>

Stock openpilot runs the model comma ships with each release. **FrogPilot**'s **"Model Manager"** lets you choose from a range of driving models instead. Open **FrogPilot → Driving Controls → Driving Model** to download the ones you want and switch between them with **"Select Driving Model"**. New models download on their own as they're released.

Not sure which one you'll like? Turn on the **"Model Randomizer"**.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-model-randomizer-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-model-randomizer-medium.svg"><img src="https://frogpilot.com/images/frogpilot-model-randomizer.svg" alt="The Model Randomizer, for when you're not sure which one you'll like, in four steps joined by arrows: it picks a different model for you at the start of every drive, asks how it went after drives longer than 15 minutes, saves your ratings to compare under Manage Model Ratings, and never picks models you add to Manage Model Blacklist." width="800"></picture></p>

It picks a different model at the start of every drive, asks how it went after drives longer than 15 minutes, and saves your ratings under **"Manage Model Ratings"** so you can compare them. Add models you don't like to **"Manage Model Blacklist"** so the randomizer never picks them.

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-speed-limit-controller.svg" width="36" height="36" align="absmiddle" alt=""></picture> Speed Limit Controller (SLC)

Matching your set speed to every new speed limit means constant fiddling with the cruise buttons, and it's easy to miss a sign. With **"Speed Limit Controller"**, you set your cruise speed once and **FrogPilot** follows the posted limit plus an offset you choose, but never goes above your set speed.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-speed-limit-sources-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-speed-limit-sources-medium.svg"><img src="https://frogpilot.com/images/frogpilot-speed-limit-sources.svg" alt="How Speed Limit Controller works. In this example, downloaded OpenStreetMap maps (priority 1) say 45 mph while your car's dashboard and the camera (2 and 3) say 40, so it uses 45 mph from your first choice, adds your 5 mph offset, and drives 50 mph, never above your set speed. Mapbox online data, with your own key, is used only when none of them has a limit." width="800"></picture></p>

In the example, the downloaded maps are first in your source priority order, so their 45 mph limit wins over the 40 mph reported by the dashboard and camera. Adding your 5 mph offset gives 50 mph, still capped by your set speed.

It reads speed limit signs with the road camera and, on supported Ford, Genesis, Hyundai, Kia, Lexus, and Toyota models, your car's dashboard. It also uses maps from **["OpenStreetMap"](https://www.openstreetmap.org)** and the speed limits along your **"Navigate on openpilot"** route, and, with your own **["Mapbox"](https://www.mapbox.com)** key, fills gaps with Mapbox's online data. To download maps, open **FrogPilot → Maps and Navigation → Map Data** and pick your countries or states in **Map Sources**. Go back, then tap **Download** beside **Download Maps** while parked and online. They update automatically every month. Add your **Public Mapbox Key** under **FrogPilot → Maps and Navigation → Navigation** to make **Use Mapbox as Fallback** available.

**"Speed Limit Filler"** fixes roads where your downloaded maps have no limit or the wrong one. It's on by default, under **FrogPilot → Maps and Navigation → Navigation**. It learns the limit from the signs the camera reads, saves it for that road and direction, and uses it in place of the map's limit the next time you drive there, until the map matches the signs. Roads with conditional limits, such as ones that change with the time of day or the weather, are skipped. With **"Share FrogPilot Data"** on, the learned limits and their sign photos are sent to FrogPilot while parked on unmetered Wi-Fi or Ethernet and used to improve speed limits for everyone using FrogPilot.

To choose how it handles limits, open **FrogPilot → Driving Controls → Gas / Brake → Speed Limit Controller → Manage**. The settings below note any submenus and tuning-level requirements.

| Setting | What it does |
|---------|--------------|
| **"Confirm New Speed Limits"**<br>Under **Quality of Life → Manage** | Asks before switching to a new limit, keeping the old one until you accept. Choose whether to confirm lower limits, higher limits, or both. It won't ask for confirmation until you select an option. |
| **"Fallback Speed"** | What it does where no limit can be found. You choose between using your set speed, keeping the last limit, and letting **"Experimental Mode"** pick the speed. Out of the box it keeps the last limit, even one from an earlier drive. Requires the **Standard** tuning level or higher |
| **"Higher Limit Lookahead Time"** and **"Lower Limit Lookahead Time"**<br>Under **Quality of Life → Manage** | Lets it start speeding up or slowing down for a new limit before you reach it, instead of right where the limit changes. Only works with limits from your downloaded maps. Requires the **Advanced** tuning level or higher |
| **"Match Speed Limit on Engage"**<br>Under **Quality of Life → Manage** | When you engage without resuming an earlier set speed, it starts at the speed limit plus your offset, not your current speed. It's only offered on cars where openpilot sets the cruise speed itself. Requires the **Standard** tuning level or higher |
| **"Override Speed"** | What happens after you press the gas past the limit. Out of the box it keeps the faster speed you reached, even if the limit drops, until you disengage or the limit rises to meet it. Requires the **Standard** tuning level or higher |
| **"Speed Limit Offsets"**<br>Tap **Manage** beside it | How far over or under the posted limit you drive, with a separate amount for each range of limits. Out of the box it drives 5 mph over on roads posted under 55 mph and 10 mph over on faster ones |
| **"Speed Limit Source Priority"** | Which source it goes by when more than one has a limit. You choose the first in the order you set, or always the highest or lowest limit reported. Requires the **Advanced** tuning level or higher |
| **"Use Mapbox as Fallback"**<br>Under **Quality of Life → Manage** | When none of your chosen sources has a limit, it sends your location to Mapbox to look one up online. Needs your own Mapbox key and an internet connection. Requires the **Standard** tuning level or higher |

**Speed limits are only as accurate as the available speed limit data. Always stay attentive and adjust your speed when necessary!**

---

### <picture><img src="https://frogpilot.com/images/frogpilot-icon-themes.svg" width="36" height="36" align="absmiddle" alt=""></picture> Themes

Make your screen yours. With **"Custom Themes"**, download theme packs and mix and match their color schemes, icon packs, sound packs, steering wheel icons, and turn signal animations. To choose your packs, open **FrogPilot → Theme and Appearance → Theme** and tap **Manage** beside **"Custom Themes"**. Turn on **"Holiday Themes"** in the **Theme** menu and **FrogPilot** dresses up on its own for thirteen holidays through the year. Build your own theme with the **"Theme Maker"** in **The Pond** and share it with the community. Open The Pond in a browser on the same Wi-Fi using the address shown under **FrogPilot → Maps and Navigation → Navigation → Manage Your Settings At**. For extra fun, the **Theme** menu also offers the Mario Kart–style **"Rainbow Path"** and **"Random Events"** for the occasional joke alert when your tuning level is **Standard** or higher. Neither one changes how it drives!

<p align="center"><img src="https://frogpilot.com/images/frogpilot-themes.jpg" alt="FrogPilot's driving screen with the Frog theme, which has green lane lines and path, a green settings button, a frog as the flag button, and a frog in a chauffeur cap as the steering wheel icon." width="800"></p>

---

**FrogPilot is driver assistance, not self-driving. Stay attentive and ready to take over. "Conditional Experimental Mode", "Curve Speed Controller", driving personality tuning, Human-Like Driving, "Speed Limit Controller", and "Traffic Mode" only work on cars where openpilot controls the gas and brake.**

And lots more!

openpilot vs **FrogPilot**
------

**FrogPilot** keeps stock openpilot's core features and adds:

#### Alerts & Screen
| Feature | openpilot | **FrogPilot** |
|---------|:---------:|:---------:|
| Set your own volume for each alert (**"Alert Volumes"**) | ❌ | ✅ |
| Turns the lane beside you red on screen when a vehicle is in your blind spot, not just when you signal (**"Blind Spot Path"**)* | ❌ | ✅ |
| Saves the last minute of the driving screen as a video with one tap, or records it whenever you like (**"Capture Recent Footage"**, **"Screen Recorder"**) | ❌ | ✅ |
| Change colors, icons, sounds, and turn signals, with automatic holiday themes (**"Custom Themes"**, **"Holiday Themes"**) | ❌ | ✅ |
| Chimes when the model predicts it's time to move, which can be before the light changes, or when the car in front pulls away (**"Green Light Alert"**, **"Lead Departing Alert"**) | ❌ | ✅ |
| Shows the posted speed limit on screen from maps, road signs, or your car's dashboard, even on cars where openpilot doesn't control the gas and brake (**"Show Speed Limits"**) | ❌ | ✅ |
| Chimes when the speed limit changes (**"Speed Limit Changed Alert"**) | ❌ | ✅ |
| Turns the screen off while driving and wakes it for alerts (**"Standby Mode"**) | ❌ | ✅ |

<details>
<summary>Settings paths and tuning levels</summary>

- **Alert Volumes:** **FrogPilot → Alerts and Sounds → Manage → Alert Volumes → Manage**. Requires the **Advanced** tuning level or higher.
- **Blind Spot Path:** **FrogPilot → Theme and Appearance → Appearance → Driving Screen Widgets → Manage**. Requires the **Standard** tuning level or higher and a car with blind spot monitoring.
- **Capture Recent Footage**, **Screen Recorder**, and **Standby Mode:** **FrogPilot → System Settings → Device Controls → Screen Settings → Manage**. **Capture Recent Footage** and **Standby Mode** require the **Standard** tuning level or higher, while **Screen Recorder** requires **Advanced** or higher.
- **Custom Themes** and **Holiday Themes:** **FrogPilot → Theme and Appearance → Theme**. Tap **Manage** beside **Custom Themes** to choose its packs.
- **Green Light Alert**, **Lead Departing Alert**, **Louder Blind Spot Alert**, and **Speed Limit Changed Alert:** **FrogPilot → Alerts and Sounds → Manage → FrogPilot Alerts → Manage**. The speed-limit alert appears when **Show Speed Limits** or **Speed Limit Filler** is on, or when **Speed Limit Controller** is on and openpilot controls the gas and brake.
- **Show Speed Limits:** **FrogPilot → Theme and Appearance → Appearance → Navigation Widgets → Manage**. This toggle is hidden when **Speed Limit Controller** is on and openpilot controls the gas and brake, because the controller already displays the limit. Requires the **Standard** tuning level or higher.

</details>

#### Comfort
| Feature | openpilot | **FrogPilot** |
|---------|:---------:|:---------:|
| Automatic door locks on Lexus and Toyota cars, locking when you shift into gear and unlocking in park (**"Automatically Lock/Unlock Doors"**)* | ❌ | ✅ |
| Brakes earlier and more gently behind other cars and, in **"Chill Mode"**, brakes half as hard with no car ahead and eases into your set speed, all on by default (**"Deceleration Profile"**, **"Human-Like Acceleration"**, **"Human-Like Following"**)† | ❌ | ✅ |
| Tune each driving personality's acceleration, braking, and following distance (**"Driving Personalities"**)† | ❌ | ✅ |
| Set how much farther back it stops behind the car ahead, up to 10 extra feet (**"Increase Stopped Distance by:"**)† | ❌ | ✅ |
| More steering strength* | ❌ | ✅ |
| Smoother steering, on by default, from a model trained on cars like yours or, where there isn't one, a lighter version that anticipates curves (**"Neural Network Feedforward (NNFF)"**, **"Neural Network Feedforward (NNFF) Lite"**)* | ❌ | ✅ |
| Stop-and-go on cars whose factory cruise control can't do it* | ❌ | ✅ |
| Set extra following distance and gentler acceleration and cornering for low visibility, rain, and snow (**"Weather Condition Offsets"**)† | ❌ | ✅ |

<details>
<summary>Settings paths and tuning levels</summary>

- **Automatically Lock/Unlock Doors:** **FrogPilot → Vehicle Settings → Vehicle Settings → Toyota/Lexus Settings → Manage**.
- **Deceleration Profile**, **Human-Like Acceleration**, and **Human-Like Following:** **FrogPilot → Driving Controls → Gas / Brake → Longitudinal Tuning → Manage**. Requires the **Advanced** tuning level or higher.
- **Driving Personalities:** **FrogPilot → Driving Controls → Gas / Brake → Driving Personalities → Manage** (requires the **Advanced** tuning level or higher), then **Manage** beside **Aggressive**, **Standard**, or **Relaxed**. **Following Distance** requires the **Advanced** tuning level or higher, while the other profile controls require **Developer**.
- **Increase Stopped Distance by:** **FrogPilot → Driving Controls → Gas / Brake → Quality of Life → Manage**. Requires the **Standard** tuning level or higher.
- **Neural Network Feedforward (NNFF)** and **Neural Network Feedforward (NNFF) Lite:** **FrogPilot → Driving Controls → Steering → Lateral Tuning → Manage**. Which one appears depends on your car and whether full NNFF is on. Requires the **Advanced** tuning level or higher.
- **Stop-and-go:** **FrogPilot → Vehicle Settings → Vehicle Settings**, then **Manage** beside your brand's settings. Look for **Stop-and-Go Hack** on supported Chevrolet Volt, Toyota, and Lexus cars, or **Stop and Go** on supported Subarus. Requires the **Advanced** tuning level or higher.
- **Weather Condition Offsets:** **FrogPilot → Driving Controls → Gas / Brake → Quality of Life → Manage → Weather Condition Offsets → Manage**, then **Manage** beside **Low Visibility**, **Rain**, **Rainstorms**, or **Snow**. Requires the **Advanced** tuning level or higher.

</details>

#### Driving
| Feature | openpilot | **FrogPilot** |
|---------|:---------:|:---------:|
| Keeps steering when you brake or cancel cruise (**"Always On Lateral"**) | ❌ | ✅ |
| Changes lanes with just the turn signal, no wheel nudge (**"Automatic Lane Changes"**) | ❌ | ✅ |
| Switches between **"Chill Mode"** and **"Experimental Mode"** on its own (**"Conditional Experimental Mode"**)† | ❌ | ✅ |
| Takes curves at the speed you like, learning from how you drive them (**"Curve Speed Controller"**)† | ❌ | ✅ |
| Choose what the following distance button does on a tap, a hold, and a long hold, and what the LKAS button does, such as toggling **"Experimental Mode"** or **"Traffic Mode"**†, or pausing steering (**"Distance Button"**, **"LKAS Button"**) | ❌ | ✅ |
| Comes to a stop in **"Chill Mode"** when the driving model expects to stop and there's no car ahead (**Force Stop at "Detected" Stop Lights/Signs**)† | ❌ | ✅ |
| Pauses steering below a speed you choose, either always or only while your turn signal is on (**"Pause Steering Below"**) | ❌ | ✅ |
| Follows posted speed limits from maps, road signs, or your car's dashboard (**"Speed Limit Controller"**)† | ❌ | ✅ |

<details>
<summary>Settings paths and tuning levels</summary>

- **Always On Lateral:** **FrogPilot → Driving Controls → Steering**. Tap **Manage** beside it for its options (requires the **Standard** tuning level or higher).
- **Automatic Lane Changes:** **FrogPilot → Driving Controls → Steering → Lane Changes → Manage**.
- **Conditional Experimental Mode**, **Curve Speed Controller**, and **Speed Limit Controller:** **FrogPilot → Driving Controls → Gas / Brake**. Tap **Manage** beside the feature you want to adjust. CEM and CSC require the **Standard** tuning level or higher. SLC is available at every tuning level, with more options at higher levels.
- **Distance Button** and **LKAS Button:** **FrogPilot → Vehicle Settings → Wheel Buttons**. Requires the **Advanced** tuning level or higher.
- **Force Stop at "Detected" Stop Lights/Signs:** **FrogPilot → Driving Controls → Gas / Brake → Quality of Life → Manage**. Requires the **Advanced** tuning level or higher.
- **Pause Steering Below:** **FrogPilot → Driving Controls → Steering → Quality of Life → Manage**. Requires the **Standard** tuning level or higher.

</details>

#### Models & Device
| Feature | openpilot | **FrogPilot** |
|---------|:---------:|:---------:|
| Fine-tune steering by hand (**"Advanced Lateral Tuning"**) | ❌ | ✅ |
| Fine-tune gas and brake by hand (**"Advanced Longitudinal Tuning"**)† | ❌ | ✅ |
| Runs on the older **comma 3** | ❌ | ✅ |
| Works with add-on hardware some owners install (**comma Pedal**, **SDSU**, and **ZSS**)* | ❌ | ✅ |
| Automatic backups of your FrogPilot install and settings, ready to restore (**"FrogPilot Backups"**, **"Settings Backups"**) | ❌ | ✅ |
| High-quality recordings when uploads are off (**"High-Quality Recording"**) | ❌ | ✅ |
| No forced internet check-ins (stock openpilot won't start after 14 days without checking for updates) | ❌ | ✅ |
| Choose your driving model (**"Select Driving Model"**), or let the **"Model Randomizer"** pick one and rate it after your drives | ❌ | ✅ |
| Shows only as many settings as you want, from a short **"Minimal"** list to every option under **"Developer"**, and starts at a level that fits how much you've driven with openpilot (**"Tuning Level"**) | ❌ | ✅ |

<details>
<summary>Settings paths and tuning levels</summary>

- **Advanced Lateral Tuning:** **FrogPilot → Driving Controls → Steering → Advanced Lateral Tuning → Manage**. Requires the **Developer** tuning level.
- **Advanced Longitudinal Tuning:** **FrogPilot → Driving Controls → Gas / Brake → Advanced Longitudinal Tuning → Manage**. Requires the **Developer** tuning level.
- **comma Pedal**, **SDSU**, and **ZSS:** supported hardware is detected automatically. Check **FrogPilot → Vehicle Settings → Vehicle Settings → Vehicle Info → View → 3rd Party Hardware Detected**. This shows which hardware was detected and isn't a toggle.
- **FrogPilot Backups** and **Settings Backups:** **FrogPilot → System Settings → Data**.
- **High-Quality Recording:** **FrogPilot → System Settings → Device Controls → Device Settings → Manage**. It appears when **Disable Uploads** is on and **Disable Onroad Only** is off. These options are hidden on **FrogPilot-Development** and **FrogPilot-Vetting**. Requires the **Advanced** tuning level or higher where available.
- **Select Driving Model** and **Model Randomizer:** **FrogPilot → Driving Controls → Driving Model**.
- **Tuning Level:** directly under **FrogPilot → Tuning Level**.

</details>

\*Select vehicles only<br>
†Cars where openpilot controls the gas and brake

And much, much more!

<a id="-how-to-install"></a>

📥 How to install
------

You need three things:

1. **A supported car.** Check [the list of 308+ supported cars](docs/CARS.md). Its **ACC** (adaptive cruise control) column shows who controls the gas and brake. On cars marked **openpilot**, openpilot does. On cars marked **openpilot available**, the experimental option is **Settings → Toggles → openpilot Longitudinal Control (Alpha)**. On cars marked **Stock**, your car's own cruise control does, and openpilot steers.
2. **A comma device.** **FrogPilot** runs on the **comma 3** and **comma 3X**.
3. **A car harness** for your car, which connects the device to it. You can buy one at [comma.ai/shop/car-harness](https://comma.ai/shop/car-harness).

Then:

1. Connect the harness and mount the device by following [comma's setup guide](https://comma.ai/setup) (written for the **comma four**).
2. When the device asks what software to install, choose **Custom Software** and enter the URL below.
   ```
   FrogPilot.download
   ```
3. Go for a drive!

To install a different branch, enter its install URL instead (see below).

🔀 Branches and updates
------

A branch is a version of **FrogPilot** you can install. They differ in how new and how tested they are.

<p align="center"><picture><source media="(max-width: 900px)" srcset="https://frogpilot.com/images/frogpilot-release-cycle-phone.svg"><source media="(max-width: 1279px)" srcset="https://frogpilot.com/images/frogpilot-release-cycle-medium.svg"><img src="https://frogpilot.com/images/frogpilot-release-cycle.svg" alt="FrogPilot's release cycle, drawn as one big gray ring that runs clockwise and stands for comma's openpilot release cycle. At the top of the ring, comma starts testing its next openpilot version. Right after that, FrogPilot-Staging moves to the openpilot version comma is testing, with FrogPilot's features. At the bottom of the ring, comma releases the new openpilot version, usually after one to three weeks of testing. Right after that, FrogPilot (main branch) gets the new openpilot version the Saturday after comma releases it. In the middle, FrogPilot-Testing is its own orange loop, updated constantly. It gets new features as soon as they're finished, and new features move up to FrogPilot-Staging." width="800"></picture></p>

**FrogPilot**'s releases follow comma's openpilot release cycle. **FrogPilot-Testing** gets new features as soon as they're finished, and those features move up to **FrogPilot-Staging**.

| Branch                     | Install&nbsp;URL          | Description | Recommended&nbsp;For     |
|----------------------------|---------------------------|-------------|--------------------------|
| FrogPilot                  | FrogPilot.download        | The release branch. Updated the Saturday after comma's official openpilot release, once it's been through Staging. | Everyone                 |
| FrogPilot&#8209;Staging    | staging.FrogPilot.download| FrogPilot on comma's upcoming openpilot release, updated as soon as comma starts testing it. Usually gets one to three weeks of testing before it becomes the release. | Early&nbsp;Adopters      |
| FrogPilot&#8209;Testing    | testing.FrogPilot.download| The newest features, as soon as they're finished. The least tested, so expect bugs! | Advanced&nbsp;Testers    |
| MAKE&#8209;PRS&#8209;HERE  | No :)                     | Workspace for pull requests. Do not install! | Contributors             |

⚠️ Safety
------

**FrogPilot** is driver assistance (adaptive cruise control and lane centering), not self-driving. The driver must stay alert and be ready to take over at all times.

openpilot's safety model is described in comma's [SAFETY.md](https://github.com/commaai/openpilot/blob/master/docs/SAFETY.md). **FrogPilot** modifies openpilot's safety code, for example to allow higher steering limits on some cars, and to let **"Always On Lateral"** keep steering after you press the brake.

❓ Common questions
------

<details>
<summary><b>Is FrogPilot free?</b></summary>

Yes. **FrogPilot** is free and open source under the MIT license. The hardware isn't. You'll need a comma device and a car harness for your car.

</details>

<details>
<summary><b>Does it drive the car by itself?</b></summary>

No. It steers for you, and on many cars it also brakes and speeds up, but you're always the driver. Keep your eyes on the road and be ready to take over. The device's driver camera checks that you're paying attention and alerts you if you aren't.

</details>

<details>
<summary><b>Will it work with my car?</b></summary>

Check [the supported cars list](docs/CARS.md). Some **FrogPilot** features also need openpilot to control your car's gas and brake. They're marked with † in the tables above.

</details>

<details>
<summary><b>Which branch should I install?</b></summary>

If you're new, start with the main **FrogPilot** branch. It's the most tested. The other branches get new features sooner, with more bugs.

</details>

<details>
<summary><b>Can I switch branches or go back to stock openpilot later?</b></summary>

Yes. **FrogPilot** is software on your comma device, so you can reinstall it with another branch's install URL, or reinstall stock openpilot on a device it supports, whenever you like.

</details>

<details>
<summary><b>What data does it share?</b></summary>

Like stock openpilot, it uploads your drives to comma by default (or to [Konik](https://konik.ai/), a separate company, on builds that aren't fully tested yet). **FrogPilot**'s own data sharing is off until you agree to it. Crash reports, device registration, and a check-in each time the device starts and after each drive are always on. The **User Data** section at the bottom has the details.

</details>

💬 Bug reports, feature requests, and help
------

If you run into a bug or have an idea for a new feature, please post it on the **[FrogPilot Discord](https://discord.frogpilot.com)**! Feedback helps improve **FrogPilot** and create a better experience for everyone!

To report a bug, please post it in [**#bug-reports**](https://discord.com/channels/1137853399715549214/1162100167110053888).  
To request a feature, please post it in [**#feature-requests**](https://discord.com/channels/1137853399715549214/1160318669839147259).  

Please include which branch you're on, your car, and your device, and as much detail as possible! Log files, photos, and videos that show the issue or idea are very helpful!

I'll do my best to respond promptly, but not every request can be addressed right away. Your feedback is always appreciated and helps make **FrogPilot** the best it can be!

🤝 Contributing
------

Pull requests are welcome! Please open them against the [**MAKE-PRS-HERE**](https://github.com/FrogAi/FrogPilot/tree/MAKE-PRS-HERE) branch, since pull requests to any other branch are closed automatically.

GitHub Issues are turned off for this repository, so please post bug reports and feature requests in the **FrogPilot Discord** channels above.

🙏 Special Thanks
------

<table>
<tr><td><a href="https://github.com/AlexandreSato">AlexandreSato</a></td><td><a href="https://github.com/bigboigahoy">bigboigahoy</a></td><td><a href="https://github.com/cfranyota">cfranyota</a></td><td><a href="https://github.com/CHaucke89">CHaucke89</a></td></tr>
<tr><td><a href="https://github.com/cydia2020">cydia2020</a></td><td><a href="https://github.com/darkerthan-black">darkerthan-black</a></td><td><a href="https://github.com/Efini">Efini</a></td><td><a href="https://github.com/eFiniLan">eFiniLan</a></td></tr>
<tr><td><a href="https://github.com/ErichMoraga">ErichMoraga</a></td><td><a href="https://github.com/garrettpall">garrettpall</a></td><td><a href="https://github.com/haraschax">haraschax</a></td><td><a href="https://github.com/henryccy">henryccy</a></td></tr>
<tr><td><a href="https://github.com/jakethesnake420">jakethesnake420</a></td><td><a href="https://github.com/jyoung8607">jyoung8607</a></td><td><a href="https://github.com/keefeere">keefeere</a></td><td><a href="https://github.com/krkeegan">krkeegan</a></td></tr>
<tr><td><a href="https://github.com/martinl">martinl</a></td><td><a href="https://github.com/mike8643">mike8643</a></td><td><a href="https://github.com/MoreTore">MoreTore</a></td><td><a href="https://github.com/multikyd">multikyd</a></td></tr>
<tr><td><a href="https://github.com/neokii">neokii</a></td><td><a href="https://github.com/nworb-cire">nworb-cire</a></td><td><a href="https://github.com/opgm">OPGM</a></td><td><a href="https://github.com/pencilpusher">pencilpusher</a></td></tr>
<tr><td><a href="https://github.com/pfeiferj">pfeiferj</a></td><td><a href="https://github.com/rav4kumar">rav4kumar</a></td><td><a href="https://github.com/sshane">sshane</a></td><td><a href="https://github.com/sunnyhaibin">sunnyhaibin</a></td></tr>
<tr><td><a href="https://github.com/syncword">syncword</a></td><td><a href="https://github.com/Thinkpad4by3">Thinkpad4by3</a></td><td><a href="https://github.com/twilsonco">twilsonco</a></td><td><a href="https://github.com/vincentw56">vincentw56</a></td></tr>
<tr><td><a href="https://github.com/xyuelin">xyuelin</a></td></tr>
</table>

⭐ Star History
------

[![Star History Chart](https://api.star-history.com/svg?repos=FrogAi/FrogPilot&type=Date)](https://www.star-history.com/#FrogAi/FrogPilot&Date)

<details>
<summary>MIT Licensed</summary>

FrogPilot, like openpilot, is released under the MIT license. Some parts of the software are released under other licenses as specified.

Any user of this software shall indemnify and hold harmless Comma.ai, Inc. and its directors, officers, employees, agents, stockholders, affiliates, subcontractors, and customers from and against all allegations, claims, actions, suits, demands, damages, liabilities, obligations, losses, settlements, judgments, costs, and expenses (including without limitation attorneys’ fees and costs) which arise out of, relate to, or result from any use of this software by user.

**THIS IS ALPHA QUALITY SOFTWARE FOR RESEARCH PURPOSES ONLY. THIS IS NOT A PRODUCT.
YOU ARE RESPONSIBLE FOR COMPLYING WITH LOCAL LAWS AND REGULATIONS.
NO WARRANTY EXPRESSED OR IMPLIED.**
</details>

<details>
<summary>User Data</summary>

Your comma device sends data to comma or Konik, FrogPilot, and Sentry.

By default, FrogPilot uploads driving data to comma's servers, like stock openpilot. You can access your data through [comma connect](https://connect.comma.ai/). Builds that aren't fully tested yet, such as **FrogPilot-Testing**, upload to the servers of [Konik](https://konik.ai/), a separate company, instead. They turn on the **"Use Konik Server"** setting, lock it on, and register your device with Konik. You can also turn on **"Use Konik Server"** yourself under **FrogPilot → System Settings → Device Controls → Device Settings → Manage** (requires the **Advanced** tuning level or higher). You can view those drives at [stable.konik.ai](https://stable.konik.ai/).

openpilot logs the road-facing cameras, CAN, GPS, IMU, magnetometer, thermal sensors, crashes, and operating system logs. Under **Settings → Toggles**, **Record and Upload Driver Camera** controls driver-facing camera recording, and the driver-facing camera is only logged if that toggle is on. The microphone isn't recorded. It also logs the ambient sound level in decibels, which is a loudness reading, not a recording.

If you agree, FrogPilot also sends the following data to its servers.

- Filtered driving logs have no video, GPS coordinates are cleared, and the VIN (your car's ID number) is removed. Your car's raw CAN data (the messages its computers send each other) is kept and, on some cars, includes GPS or the VIN.
- About 15 seconds of road camera video when a supported car's dashboard shows a new speed limit, when the speed limit sign reader sees a sign it isn't sure of, and for some of the limits it reads, linked to your device. No GPS coordinates or recording time are attached, but the video is uploaded as recorded and can show license plates, people, and identifiable places.
- Speed limits learned by **"Speed Limit Filler"**, when it's on, each with the map ID of the road, the direction it applies to, the GPS location and heading where the sign was seen, the month, and how far the car drove with it, linked to your device. Limits learned while sharing is off aren't included. Each one also includes a cropped photo of the sign it was read from, with the GPS location, heading, and month it was taken, and the photo can show part of the road around the sign. Roads where the sign matched your map's limit are sent too, with the limit and the month, to measure how accurate the sign reader is. The road IDs and locations show where the car has been driven. They're used to improve speed limits for everyone using FrogPilot.
- usage statistics, which are your car's details, your drive totals, your FrogPilot settings, and your nearest city, state, and country, linked to your device.

FrogPilot asks during setup whether you agree, and you can change your answer later with **"Share FrogPilot Data"** under **Settings → Software**. Drives recorded before you agreed are never uploaded to FrogPilot. Driving logs, road camera clips, and learned speed limits only upload over Ethernet or Wi-Fi while your car is off.

FrogPilot also registers your device with FrogPilot's server (when it first starts and after updates), checks in each time the device starts and after each drive to count active devices (with nothing in it unless you agreed to share), and sends crash reports to Sentry, a crash-reporting service. No setting turns these off. When you turn on **"Weather Condition Offsets"** under **FrogPilot → Driving Controls → Gas / Brake → Quality of Life → Manage** (requires the **Advanced** tuning level or higher), it sends your location to FrogPilot's server to check the weather. To add your own OpenWeatherMap key, open **Weather Condition Offsets → Manage → Set Your Own Key → Add**. Once you've added your key, FrogPilot tries OpenWeatherMap first.

When you send a bug report with **"Report a Bug or an Issue"** under **FrogPilot → System Settings → Utilities**, or with **"Report an Issue"** in **The Pond**, FrogPilot's server gets what went wrong, your Discord name, your settings, and the end of the most recent error log. In **The Pond**, you can also pick the drive it happened on, and only then are that drive's logs sent with the report, as recorded. They include exact locations and times, your car's data and VIN, driver monitoring, your device's settings and IDs, and road snapshots about every 5 seconds, and FrogPilot keeps them until they're deleted. **"Quick report"** sends the drive's logs from start to finish. **"Full details"** also sends the full logs and low-res road video for the minute you mark, and the video can show license plates and people. These logs start uploading right away on any connection, and on a metered connection The Pond shows their size and asks first.

**"Disable Uploads"** is under **FrogPilot → System Settings → Device Controls → Device Settings → Manage**. It requires the **Advanced** tuning level or higher, selected under **FrogPilot → Tuning Level**, and is hidden on **FrogPilot-Development** and **FrogPilot-Vetting**.

- It stops the automatic uploads of your drives to comma or Konik, and FrogPilot's driving log and learned speed limit uploads. Its **"Disable Onroad Only"** button on the same row only pauses the uploads to comma or Konik while you drive and lets them finish once you park.
- It doesn't stop crash reports, bug reports you send, device registration, the usage statistics, or the device's connection to comma or Konik, which still sends system logs and uploads files when the server requests them.

When you first set up FrogPilot, it asks you to accept comma's terms. Data sent to comma is covered by comma's [Terms & Privacy](https://comma.ai/terms), which say comma owns all data conveyed to it through openpilot. Konik's terms are at [konik.ai/privacy](https://konik.ai/privacy/).
</details>

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



### [< FrogPilot FrogPilot >](https://github.com/reopenpilot/openpilot-archive/commits/fp-FrogPilot-20261107-0827/)
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
> > <details><summary>20251115-1900</summary>
> >
> > #### fp-FrogPilot-20251115-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251115-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251115-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251129-1900</summary>
> >
> > #### fp-FrogPilot-20251129-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251129-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251129-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251201-1458</summary>
> >
> > #### fp-FrogPilot-20251201-1458
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251201-1458
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251201-1458
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251220-1900</summary>
> >
> > #### fp-FrogPilot-20251220-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251220-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251220-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251230-2346</summary>
> >
> > #### fp-FrogPilot-20251230-2346
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251230-2346
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251230-2346
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251231-0717</summary>
> >
> > #### fp-FrogPilot-20251231-0717
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20251231-0717
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20251231-0717
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260228-1900</summary>
> >
> > #### fp-FrogPilot-20260228-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260228-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260228-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260419-0902</summary>
> >
> > #### fp-FrogPilot-20260419-0902
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260419-0902
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260419-0902
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260422-0935</summary>
> >
> > #### fp-FrogPilot-20260422-0935
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260422-0935
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260422-0935
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260519-1923</summary>
> >
> > #### fp-FrogPilot-20260519-1923
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260519-1923
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260519-1923
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260525-0519</summary>
> >
> > #### fp-FrogPilot-20260525-0519
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260525-0519
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260525-0519
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260704-1900</summary>
> >
> > #### fp-FrogPilot-20260704-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260704-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260704-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260705-1242</summary>
> >
> > #### fp-FrogPilot-20260705-1242
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260705-1242
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260705-1242
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260706-0432</summary>
> >
> > #### fp-FrogPilot-20260706-0432
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260706-0432
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260706-0432
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260706-0811</summary>
> >
> > #### fp-FrogPilot-20260706-0811
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260706-0811
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260706-0811
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260707-0608</summary>
> >
> > #### fp-FrogPilot-20260707-0608
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260707-0608
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260707-0608
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260707-0618</summary>
> >
> > #### fp-FrogPilot-20260707-0618
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260707-0618
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260707-0618
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260707-0714</summary>
> >
> > #### fp-FrogPilot-20260707-0714
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260707-0714
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260707-0714
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260708-0118</summary>
> >
> > #### fp-FrogPilot-20260708-0118
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260708-0118
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260708-0118
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260708-1806</summary>
> >
> > #### fp-FrogPilot-20260708-1806
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20260708-1806
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20260708-1806
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261031-1900</summary>
> >
> > #### fp-FrogPilot-20261031-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20261031-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20261031-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261102-0440</summary>
> >
> > #### fp-FrogPilot-20261102-0440
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20261102-0440
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20261102-0440
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261102-2355</summary>
> >
> > #### fp-FrogPilot-20261102-2355
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20261102-2355
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20261102-2355
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261107-0827</summary>
> >
> > #### fp-FrogPilot-20261107-0827
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-20261107-0827
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-20261107-0827
> > ```
> >
> > </details>
> >
>
> </details>



### [< FrogPilot FrogPilot-Staging >](https://github.com/reopenpilot/openpilot-archive/commits/fp-FrogPilot-Staging-20261107-0827/)
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
> > <details><summary>20250228-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20250228-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20250228-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20250228-1900
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
> > <details><summary>20251115-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20251115-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251115-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251115-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251116-1117</summary>
> >
> > #### fp-FrogPilot-Staging-20251116-1117
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251116-1117
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251116-1117
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251129-0024</summary>
> >
> > #### fp-FrogPilot-Staging-20251129-0024
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251129-0024
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251129-0024
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251129-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20251129-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251129-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251129-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251201-1457</summary>
> >
> > #### fp-FrogPilot-Staging-20251201-1457
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251201-1457
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251201-1457
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251215-0301</summary>
> >
> > #### fp-FrogPilot-Staging-20251215-0301
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251215-0301
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251215-0301
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251215-1902</summary>
> >
> > #### fp-FrogPilot-Staging-20251215-1902
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251215-1902
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251215-1902
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251219-2218</summary>
> >
> > #### fp-FrogPilot-Staging-20251219-2218
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251219-2218
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251219-2218
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20251220-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20251220-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20251220-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20251220-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260213-2013</summary>
> >
> > #### fp-FrogPilot-Staging-20260213-2013
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260213-2013
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260213-2013
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260214-0632</summary>
> >
> > #### fp-FrogPilot-Staging-20260214-0632
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260214-0632
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260214-0632
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260214-0636</summary>
> >
> > #### fp-FrogPilot-Staging-20260214-0636
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260214-0636
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260214-0636
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260216-1038</summary>
> >
> > #### fp-FrogPilot-Staging-20260216-1038
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260216-1038
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260216-1038
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260216-1045</summary>
> >
> > #### fp-FrogPilot-Staging-20260216-1045
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260216-1045
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260216-1045
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260216-1228</summary>
> >
> > #### fp-FrogPilot-Staging-20260216-1228
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260216-1228
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260216-1228
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260217-0056</summary>
> >
> > #### fp-FrogPilot-Staging-20260217-0056
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260217-0056
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260217-0056
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260217-0128</summary>
> >
> > #### fp-FrogPilot-Staging-20260217-0128
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260217-0128
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260217-0128
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260228-0725</summary>
> >
> > #### fp-FrogPilot-Staging-20260228-0725
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260228-0725
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260228-0725
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260228-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20260228-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260228-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260228-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260306-0936</summary>
> >
> > #### fp-FrogPilot-Staging-20260306-0936
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260306-0936
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260306-0936
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260306-2035</summary>
> >
> > #### fp-FrogPilot-Staging-20260306-2035
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260306-2035
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260306-2035
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260414-2240</summary>
> >
> > #### fp-FrogPilot-Staging-20260414-2240
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260414-2240
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260414-2240
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260419-0902</summary>
> >
> > #### fp-FrogPilot-Staging-20260419-0902
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260419-0902
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260419-0902
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260525-0518</summary>
> >
> > #### fp-FrogPilot-Staging-20260525-0518
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260525-0518
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260525-0518
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260701-0021</summary>
> >
> > #### fp-FrogPilot-Staging-20260701-0021
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260701-0021
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260701-0021
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260702-0542</summary>
> >
> > #### fp-FrogPilot-Staging-20260702-0542
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260702-0542
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260702-0542
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260704-1548</summary>
> >
> > #### fp-FrogPilot-Staging-20260704-1548
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260704-1548
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260704-1548
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260704-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20260704-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260704-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260704-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260828-0834</summary>
> >
> > #### fp-FrogPilot-Staging-20260828-0834
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260828-0834
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260828-0834
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260828-1154</summary>
> >
> > #### fp-FrogPilot-Staging-20260828-1154
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260828-1154
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260828-1154
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260828-1209</summary>
> >
> > #### fp-FrogPilot-Staging-20260828-1209
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260828-1209
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260828-1209
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260828-1221</summary>
> >
> > #### fp-FrogPilot-Staging-20260828-1221
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260828-1221
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260828-1221
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260831-0148</summary>
> >
> > #### fp-FrogPilot-Staging-20260831-0148
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260831-0148
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260831-0148
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260901-1530</summary>
> >
> > #### fp-FrogPilot-Staging-20260901-1530
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260901-1530
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260901-1530
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260901-2105</summary>
> >
> > #### fp-FrogPilot-Staging-20260901-2105
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260901-2105
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260901-2105
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260903-2115</summary>
> >
> > #### fp-FrogPilot-Staging-20260903-2115
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260903-2115
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260903-2115
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260905-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20260905-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260905-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260905-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260911-2007</summary>
> >
> > #### fp-FrogPilot-Staging-20260911-2007
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260911-2007
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260911-2007
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260912-1621</summary>
> >
> > #### fp-FrogPilot-Staging-20260912-1621
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260912-1621
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260912-1621
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260913-0227</summary>
> >
> > #### fp-FrogPilot-Staging-20260913-0227
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260913-0227
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260913-0227
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260913-1916</summary>
> >
> > #### fp-FrogPilot-Staging-20260913-1916
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260913-1916
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260913-1916
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260914-1005</summary>
> >
> > #### fp-FrogPilot-Staging-20260914-1005
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260914-1005
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260914-1005
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260919-0648</summary>
> >
> > #### fp-FrogPilot-Staging-20260919-0648
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260919-0648
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260919-0648
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260919-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20260919-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260919-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260919-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260926-0115</summary>
> >
> > #### fp-FrogPilot-Staging-20260926-0115
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260926-0115
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260926-0115
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260926-0155</summary>
> >
> > #### fp-FrogPilot-Staging-20260926-0155
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260926-0155
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260926-0155
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20260926-0507</summary>
> >
> > #### fp-FrogPilot-Staging-20260926-0507
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20260926-0507
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20260926-0507
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261003-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20261003-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261003-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261003-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261029-2245</summary>
> >
> > #### fp-FrogPilot-Staging-20261029-2245
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261029-2245
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261029-2245
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261030-0948</summary>
> >
> > #### fp-FrogPilot-Staging-20261030-0948
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261030-0948
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261030-0948
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261031-1900</summary>
> >
> > #### fp-FrogPilot-Staging-20261031-1900
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261031-1900
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261031-1900
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261102-0440</summary>
> >
> > #### fp-FrogPilot-Staging-20261102-0440
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261102-0440
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261102-0440
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261102-2355</summary>
> >
> > #### fp-FrogPilot-Staging-20261102-2355
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261102-2355
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261102-2355
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261104-0716</summary>
> >
> > #### fp-FrogPilot-Staging-20261104-0716
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261104-0716
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261104-0716
> > ```
> >
> > </details>
> >
> 
> > <details><summary>20261107-0827</summary>
> >
> > #### fp-FrogPilot-Staging-20261107-0827
> >
> > ```
> > https://smiskol.com/fork/reopenpilot/fp-FrogPilot-Staging-20261107-0827
> > ```
> > ```
> > curl -fsSL https://bit.ly/reopenpilot | bash -s fp-FrogPilot-Staging-20261107-0827
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
