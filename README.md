Pebble Ponies
=============

This Pebble app is a simple watchface which displays the time, date, and a random pony each minute. Seventy images are included.
There is a small battery meter in the top right. The watchface supports black on white text or white on black text through the settings.
This is a SDK 3.0 watchface. It has been designed for the Pebble Time and works best on that platform.

![](https://raw.githubusercontent.com/davidfg4/pebble-ponies/master/screenshot01.png "Screenshot 1")
![](https://raw.githubusercontent.com/davidfg4/pebble-ponies/master/screenshot02.png "Screenshot 2")

This watch does work on the original black and white Pebble, although it is limited to 30 images due to space constraints.

Install
-------

```
pebble build && pebble install
```

Images created with
```
mogrify -resize 144x168 -level 40x100% *.png
```
Images are slightly oversatured to compensate for the Pebble Time's undersatured screen and 64 color palette.

Image convered to B&W with
```
mogrify -background white -flatten *.png;mogrify -monochrome *.png
```

Credits
-------

Many thanks to the following vector artists for their vectors:
* [RedtoxinDash](http://redtoxindash.deviantart.com/art/A-Dash-of-adorable-381915154)
* [EnergyFrost](http://energyfrost.deviantart.com/art/Applejack-362275674)
* [JennieOo](http://jennieoo.deviantart.com/art/Balloons-326256424)
* [thatguy1945](http://thatguy1945.deviantart.com/art/Fluttershy-is-umm-ready-355125933)
* [zanoslayer](http://izanoslayer.deviantart.com/art/Pissed-Rarity-325009559)
* [davidfg4](http://davidfg4.deviantart.com/art/Rainbow-Dash-Flying-415111595)
* [uxyd](http://uxyd.deviantart.com/art/Rarity-329826115)
* [AzizTheWazon](http://azizthewazon.deviantart.com/art/Twi-437490296)
* [DJDavid98](http://djdavid98.deviantart.com/art/Twilight-pondering-S04E23-451539015)
* [SierraEx](http://sierraex.deviantart.com/art/Berry-Punch-Sleeping-244895376)
* [nano23823](http://nano23823.deviantart.com/art/Blossomforth-can-t-see-450405312)
* [Ready2Fail](http://ready2fail.deviantart.com/art/Vector-Spitfire-in-Uniform-404869508)
* [TecknoJock](http://tecknojock.deviantart.com/art/Spitfire-208286741)
* [StarshineCelestalis](http://starshinecelestalis.deviantart.com/art/Soarin-Royal-Wedding-Vector-295757052)
* [Kishmond](http://kishmond.deviantart.com/art/Braeburn-1-207192020)
* [bobsicle0](http://bobsicle0.deviantart.com/art/Celestia-Everything-Went-Better-Than-Expected-448614547)
* [NightFlyer22](http://nightflyer22.deviantart.com/art/You-can-t-get-away-from-your-own-shadow-533039435)
* [BlackGryph0n](http://blackgryph0n.deviantart.com/art/Cheerilee-is-not-amused-268803188)
* [Godoffury](http://godoffury.deviantart.com/art/Queen-Chrysalis-443024992)
* [Skie-Vinyl](http://skie-vinyl.deviantart.com/art/Cloudchaser-437322873)
* [AzizTheWazon](http://azizthewazon.deviantart.com/art/S02E22-Flitter-307896268)
* [Creshosk](http://creshosk.deviantart.com/art/Sad-Eyed-Apple-Bloom-245293300)
* [irestorm-CAN](http://firestorm-can.deviantart.com/art/Babs-Seed-Eep-339700251)
* [Atmospark](http://atmospark.deviantart.com/art/Scoots-is-Oh-So-Happy-315644758)
* [MoongazePonies](http://moongazeponies.deviantart.com/art/Sweetie-Belle-being-adorable-204345679)
* [PixelKitties](http://pixelkitties.deviantart.com/art/Coco-Pommel-is-Best-Pony-Next-to-Trixie-of-course-424650960)
* [GameMasterLuna](http://gamemasterluna.deviantart.com/art/Minuette-Colgate-439057811)
* [Racefox](http://racefox.deviantart.com/art/That-s-mine-418520769)
* [liamwhite1](http://liamwhite1.deviantart.com/art/AREN-T-I-FLYING-YET-459239423)
* [Mihaaaa](http://mihaaaa.deviantart.com/art/Doctor-Whooves-singing-214577524)
* [Liggliluff](http://liggliluff.deviantart.com/art/Golden-Harvest-Happy-Pose-280227756)
* [NabbieKitty](http://nabbiekitty.deviantart.com/art/Discord-336587397)
* [Ambassad0r](http://ambassad0r.deviantart.com/art/Night-Glider-518678939)
* [Abion47](http://abion47.deviantart.com/art/Double-Diamond-Skiier-527011500)
* [Turbo740](http://turbo740.deviantart.com/art/Gilda-318173491)
* [HankOfficer](http://hankofficer.deviantart.com/art/Lightning-Dust-is-ready-SVG-368971308)
* [horsefan999](http://horsefan999.deviantart.com/art/Lyra-Vector-393338305)
* [scrimpeh](http://scrimpeh.deviantart.com/art/Bon-Bon-Vector-293112895)
* [WeegeeStareAtYou](http://weegeestareatyou.deviantart.com/art/Maud-Pie-Vector-448657631)
* [feitaru](http://feitaru.deviantart.com/art/Pound-Cake-Season-2-Poster-333299673)
* [lockiesajt](http://lockiesajt.deviantart.com/art/Nurse-Redheart-279781767)
* [Yanoda](http://yanoda.deviantart.com/art/Eww-Tulips-334763790)
* [Kooner-cz](http://kooner-cz.deviantart.com/art/Octavia-Classy-258205887)
* [NightFlyer22](http://nightflyer22.deviantart.com/art/DJ-Vinyl-Scratch-Vector-527607352)
* [Parclytaxel](http://parclytaxel.deviantart.com/art/8-2-Millimetres-From-Lead-Shot-398864435)
* [InuHoshi-to-DarkPen](http://inuhoshi-to-darkpen.deviantart.com/art/Cadance-358563694)
* [NightFlyer22](http://nightflyer22.deviantart.com/art/Starlight-Glimmer-wants-you-524753459)
* [Stabzor](http://stabzor.deviantart.com/art/Sunset-Shimmer-386168631)
* [datNaro](http://datnaro.deviantart.com/art/Trixie-258517382)
* [ShelltoonTV](http://shelltoontv.deviantart.com/art/Zecora-201202325)
* [YellowTDash](http://yellowtdash.deviantart.com/art/allie-way-opened-eyes-269133452)
* [ForsakenSharikan](http://forsakensharikan.deviantart.com/art/Amethyst-Star-Shopping-298670444)
* [DJDavid98](http://djdavid98.deviantart.com/art/Apple-Fritter-staring-into-your-soul-513906995)
* [Anxet](http://anxet.deviantart.com/art/Big-Macintosh-Vector-309338349)
* [Liggliluff](http://liggliluff.deviantart.com/art/Diamond-Tiara-Snooty-280511569)
* [miketueur](http://miketueur.deviantart.com/art/Silver-Spoon-257695689)
* [CawinEMD](http://cawinemd.deviantart.com/art/FeatherWeight-293812009)
* [90Sigma](http://90sigma.deviantart.com/art/Fleur-de-Lis-397350038)
* [ChainChomp2](http://chainchomp2.deviantart.com/art/Nervous-Thunderlane-416826041)
* [90Sigma](http://90sigma.deviantart.com/art/Aloe-415298541)
* [90Sigma](http://90sigma.deviantart.com/art/Lotus-423007322)
* [Ambassad0r](http://ambassad0r.deviantart.com/art/Just-a-Rumble-385102449)
* [dasprid](http://dasprid.deviantart.com/art/Ms-Peachbottom-The-Real-Games-Inspector-424212535)
* [Jeatz-Axl](http://jeatz-axl.deviantart.com/art/Pip-Mad-437116961)
* [Jeatz-Axl](http://jeatz-axl.deviantart.com/art/Twilight-Velvet-442111330)
* [Jeatz-Axl](http://jeatz-axl.deviantart.com/art/Night-Light-442109384)
* [Kooner-cz](http://kooner-cz.deviantart.com/art/Seafoam-vector-254631610)
* [Powerpuncher](http://powerpuncher.deviantart.com/art/Spike-Wait-a-minute-527086034)
* [Durpy](http://durpy.deviantart.com/art/Mayor-Mare-vectored-258412779)
* [90Sigma](http://90sigma.deviantart.com/art/King-Sombra-335049960)
