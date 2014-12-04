// TL1023

#include "atlas/grids/reduced_gg/reduced_gg.h"

namespace atlas {
namespace grids {
namespace reduced_gg {

register_BuilderT1(Grid,N512,N512::grid_type_str());

void N512::construct()
{
  int N=512;
  int lon[] = {
    18,
    25,
    32,
    40,
    45,
    50,
    60,
    60,
    72,
    72,
    75,
    81,
    90,
    96,
    96,
   100,
   108,
   120,
   125,
   128,
   135,
   144,
   150,
   160,
   160,
   180,
   180,
   180,
   192,
   192,
   200,
   216,
   216,
   225,
   225,
   240,
   240,
   243,
   250,
   256,
   270,
   270,
   288,
   288,
   288,
   300,
   320,
   320,
   320,
   320,
   360,
   360,
   360,
   360,
   360,
   360,
   375,
   375,
   384,
   384,
   400,
   400,
   400,
   432,
   432,
   432,
   432,
   450,
   450,
   450,
   480,
   480,
   480,
   480,
   480,
   486,
   500,
   500,
   512,
   512,
   540,
   540,
   540,
   540,
   540,
   576,
   576,
   576,
   576,
   576,
   576,
   600,
   600,
   600,
   640,
   640,
   640,
   640,
   640,
   640,
   640,
   648,
   675,
   675,
   675,
   675,
   675,
   720,
   720,
   720,
   720,
   720,
   720,
   720,
   729,
   729,
   750,
   750,
   750,
   768,
   768,
   768,
   800,
   800,
   800,
   800,
   800,
   800,
   810,
   864,
   864,
   864,
   864,
   864,
   864,
   864,
   864,
   864,
   864,
   900,
   900,
   900,
   900,
   900,
   900,
   960,
   960,
   960,
   960,
   960,
   960,
   960,
   960,
   960,
   960,
   960,
   972,
   972,
  1000,
  1000,
  1000,
  1000,
  1000,
  1024,
  1024,
  1024,
  1024,
  1080,
  1080,
  1080,
  1080,
  1080,
  1080,
  1080,
  1080,
  1080,
  1080,
  1125,
  1125,
  1125,
  1125,
  1125,
  1125,
  1125,
  1125,
  1125,
  1152,
  1152,
  1152,
  1152,
  1152,
  1200,
  1200,
  1200,
  1200,
  1200,
  1200,
  1200,
  1200,
  1200,
  1215,
  1215,
  1215,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1280,
  1296,
  1296,
  1296,
  1350,
  1350,
  1350,
  1350,
  1350,
  1350,
  1350,
  1350,
  1350,
  1350,
  1350,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1440,
  1458,
  1458,
  1458,
  1458,
  1500,
  1500,
  1500,
  1500,
  1500,
  1500,
  1500,
  1500,
  1500,
  1500,
  1536,
  1536,
  1536,
  1536,
  1536,
  1536,
  1536,
  1536,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1600,
  1620,
  1620,
  1620,
  1620,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1728,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1800,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1875,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1920,
  1944,
  1944,
  1944,
  1944,
  1944,
  1944,
  1944,
  1944,
  1944,
  1944,
  1944,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2000,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2025,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048,
  2048
  };
  double lat[] =
  {
    89.8655086877001708,
    89.6912863194274337,
    89.5160350739077018,
    89.3405513611337341,
    89.1649794680404995,
    88.9893649042767123,
    88.8137264936948014,
    88.6380734172450389,
    88.4624106824208809,
    88.2867412513397625,
    88.1110669877975425,
    87.9353891229293367,
    87.7597085025584249,
    87.5840257269503155,
    87.4083412338709280,
    87.2326553500760582,
    87.0569683243937220,
    86.8812803496438590,
    86.7055915775544861,
    86.5299021291524326,
    86.3542121021540936,
    86.1785215763183885,
    86.0028306173904582,
    85.8271392800498063,
    85.6514476101438333,
    85.4757556464017938,
    85.3000634217647615,
    85.1243709644274276,
    84.9486782986635518,
    84.7729854454845935,
    84.5972924231695629,
    84.4215992476957382,
    84.2459059330893467,
    84.0702124917148836,
    83.8945189345139397,
    83.7188252712042811,
    83.5431315104462442,
    83.3674376599825706,
    83.1917437267571387,
    83.0160497170150933,
    82.8403556363888356,
    82.6646614899710244,
    82.4889672823780984,
    82.3132730178044341,
    82.1375787000695539,
    81.9618843326590110,
    81.7861899187603711,
    81.6104954612940503,
    81.4348009629409404,
    81.2591064261664258,
    81.0834118532415857,
    80.9077172462619103,
    80.7320226071642395,
    80.5563279377409742,
    80.3806332396538465,
    80.2049385144452600,
    80.0292437635488909,
    79.8535489882992238,
    79.6778541899398220,
    79.5021593696309878,
    79.3264645284567109,
    79.1507696674306800,
    78.9750747875020664,
    78.7993798895604698,
    78.6236849744404651,
    78.4479900429259231,
    78.2722950957537620,
    78.0966001336173576,
    77.9209051571697415,
    77.7452101670265847,
    77.5695151637686138,
    77.3938201479443535,
    77.2181251200719743,
    77.0424300806417222,
    76.8667350301175105,
    76.6910399689387816,
    76.5153448975221124,
    76.3396498162626358,
    76.1639547255353477,
    75.9882596256965428,
    75.8125645170848372,
    75.6368694000221922,
    75.4611742748151499,
    75.2854791417555020,
    75.1097840011213407,
    74.9340888531777694,
    74.7583936981776134,
    74.5826985363622441,
    74.4070033679621758,
    74.2313081931975489,
    74.0556130122788971,
    73.8799178254075315,
    73.7042226327760801,
    73.5285274345689999,
    73.3528322309629175,
    73.1771370221270558,
    73.0014418082237455,
    72.8257465894085811,
    72.6500513658308762,
    72.4743561376339898,
    72.2986609049555682,
    72.1229656679278293,
    71.9472704266778891,
    71.7715751813279184,
    71.5958799319954835,
    71.4201846787936319,
    71.2444894218312328,
    71.0687941612130771,
    70.8930988970401188,
    70.7174036294096595,
    70.5417083584154341,
    70.3660130841478946,
    70.1903178066941820,
    70.0146225261385098,
    69.8389272425619936,
    69.6632319560431341,
    69.4875366666575474,
    69.3118413744784760,
    69.1361460795765339,
    68.9604507820200467,
    68.7847554818751235,
    68.6090601792056134,
    68.4333648740733338,
    68.2576695665381123,
    68.0819742566578014,
    67.9062789444885198,
    67.7305836300845101,
    67.5548883134983953,
    67.3791929947810928,
    67.2034976739820138,
    67.0278023511490488,
    66.8521070263285822,
    66.6764116995656764,
    66.5007163709039872,
    66.3250210403859199,
    66.1493257080526007,
    65.9736303739439762,
    65.7979350380987853,
    65.6222397005547293,
    65.4465443613483728,
    65.2708490205152714,
    65.0951536780899431,
    64.9194583341059683,
    64.7437629885960320,
    64.5680676415918100,
    64.3923722931241969,
    64.2166769432232627,
    64.0409815919181540,
    63.8652862392373635,
    63.6895908852085384,
    63.5138955298586225,
    63.3382001732138349,
    63.1625048152997408,
    62.9868094561412235,
    62.8111140957625125,
    62.6354187341872262,
    62.4597233714383862,
    62.2840280075384314,
    62.1083326425092181,
    61.9326372763720698,
    61.7569419091478125,
    61.5812465408566752,
    61.4055511715184750,
    61.2298558011524889,
    61.0541604297775748,
    60.8784650574120789,
    60.7027696840739779,
    60.5270743097807511,
    60.3513789345495226,
    60.1756835583969547,
    59.9999881813393969,
    59.8242928033927370,
    59.6485974245725643,
    59.4729020448940489,
    59.2972066643720694,
    59.1215112830211282,
    58.9458159008554361,
    58.7701205178888273,
    58.5944251341348874,
    58.4187297496068965,
    58.2430343643177864,
    58.0673389782802474,
    57.8916435915067069,
    57.7159482040092868,
    57.5402528157998461,
    57.3645574268900518,
    57.1888620372912300,
    57.0131666470145291,
    56.8374712560708630,
    56.6617758644708758,
    56.4860804722250194,
    56.3103850793435114,
    56.1346896858363991,
    55.9589942917134522,
    55.7832988969843129,
    55.6076035016583745,
    55.4319081057448528,
    55.2562127092528215,
    55.0805173121911196,
    54.9048219145684087,
    54.7291265163932081,
    54.5534311176738811,
    54.3777357184185846,
    54.2020403186353263,
    54.0263449183319864,
    53.8506495175162669,
    53.6749541161957140,
    53.4992587143777740,
    53.3235633120696946,
    53.1478679092786308,
    52.9721725060115745,
    52.7964771022753965,
    52.6207816980768541,
    52.4450862934225412,
    52.2693908883189735,
    52.0936954827725245,
    51.9180000767894398,
    51.7423046703758658,
    51.5666092635378419,
    51.3909138562813013,
    51.2152184486120348,
    51.0395230405357765,
    50.8638276320581468,
    50.6881322231846241,
    50.5124368139206652,
    50.3367414042715566,
    50.1610459942425422,
    49.9853505838387591,
    49.8096551730652237,
    49.6339597619269597,
    49.4582643504287773,
    49.2825689385755012,
    49.1068735263718352,
    48.9311781138224049,
    48.7554827009317719,
    48.5797872877043986,
    48.4040918741447115,
    48.2283964602570165,
    48.0527010460455699,
    47.8770056315145567,
    47.7013102166681122,
    47.5256148015102795,
    47.3499193860450305,
    47.1742239702763015,
    46.9985285542079367,
    46.8228331378437446,
    46.6471377211874412,
    46.4714423042427143,
    46.2957468870131734,
    46.1200514695023926,
    45.9443560517138536,
    45.7686606336510309,
    45.5929652153172924,
    45.4172697967159991,
    45.2415743778504336,
    45.0658789587238360,
    44.8901835393394038,
    44.7144881197002775,
    44.5387926998095622,
    44.3630972796702707,
    44.1874018592854370,
    44.0117064386580097,
    43.8360110177908950,
    43.6603155966869565,
    43.4846201753490504,
    43.3089247537799267,
    43.1332293319823705,
    42.9575339099590394,
    42.7818384877126334,
    42.6061430652457602,
    42.4304476425610204,
    42.2547522196609648,
    42.0790567965480875,
    41.9033613732248895,
    41.7276659496938152,
    41.5519705259572731,
    41.3762751020176154,
    41.2005796778772009,
    41.0248842535383602,
    40.8491888290033387,
    40.6734934042743959,
    40.4977979793537415,
    40.3221025542435640,
    40.1464071289460307,
    39.9707117034632304,
    39.7950162777973020,
    39.6193208519502775,
    39.4436254259242247,
    39.2679299997211544,
    39.0922345733430276,
    38.9165391467918340,
    38.7408437200694848,
    38.5651482931779128,
    38.3894528661189653,
    38.2137574388945396,
    38.0380620115064687,
    37.8623665839565291,
    37.6866711562465326,
    37.5109757283782344,
    37.3352803003533822,
    37.1595848721737099,
    36.9838894438408943,
    36.8081940153566052,
    36.6324985867225337,
    36.4568031579402714,
    36.2811077290114739,
    36.1054122999377043,
    35.9297168707205543,
    35.7540214413615658,
    35.5783260118622877,
    35.4026305822242406,
    35.2269351524489025,
    35.0512397225377867,
    34.8755442924923145,
    34.6998488623139707,
    34.5241534320041552,
    34.3484580015642962,
    34.1727625709957792,
    33.9970671402999969,
    33.8213717094782780,
    33.6456762785320080,
    33.4699808474624874,
    33.2942854162710447,
    33.1185899849589802,
    32.9428945535275730,
    32.7671991219781020,
    32.5915036903118036,
    32.4158082585299354,
    32.2401128266337196,
    32.0644173946243569,
    31.8887219625030802,
    31.7130265302710477,
    31.5373310979294459,
    31.3616356654794295,
    31.1859402329221425,
    31.0102448002587181,
    30.8345493674902968,
    30.6588539346179694,
    30.4831585016428406,
    30.3074630685659976,
    30.1317676353885240,
    29.9560722021114643,
    29.7803767687358771,
    29.6046813352628106,
    29.4289859016932915,
    29.2532904680283536,
    29.0775950342689526,
    28.9018996004161721,
    28.7262041664709145,
    28.5505087324342206,
    28.3748132983070285,
    28.1991178640902973,
    28.0234224297849828,
    27.8477269953920192,
    27.6720315609123517,
    27.4963361263468755,
    27.3206406916965037,
    27.1449452569621634,
    26.9692498221447252,
    26.7935543872450772,
    26.6178589522640969,
    26.4421635172026441,
    26.2664680820616070,
    26.0907726468418062,
    25.9150772115441050,
    25.7393817761693207,
    25.5636863407182915,
    25.3879909051918240,
    25.2122954695907460,
    25.0366000339158603,
    24.8609045981679451,
    24.6852091623478245,
    24.5095137264562339,
    24.3338182904939906,
    24.1581228544618369,
    23.9824274183605510,
    23.8067319821908683,
    23.6310365459535561,
    23.4553411096493498,
    23.2796456732789743,
    23.1039502368431684,
    22.9282548003426605,
    22.7525593637781611,
    22.5768639271503631,
    22.4011684904600017,
    22.2254730537077307,
    22.0497776168942963,
    21.8740821800203484,
    21.6983867430865693,
    21.5226913060936340,
    21.3469958690422565,
    21.1713004319330373,
    20.9956049947666727,
    20.8199095575437987,
    20.6442141202650689,
    20.4685186829311405,
    20.2928232455426176,
    20.1171278081001823,
    19.9414323706044136,
    19.7657369330559760,
    19.5900414954554520,
    19.4143460578034777,
    19.2386506201006675,
    19.0629551823476184,
    18.8872597445449237,
    18.7115643066931874,
    18.5358688687930062,
    18.3601734308449522,
    18.1844779928496187,
    18.0087825548075848,
    17.8330871167194296,
    17.6573916785857072,
    17.4816962404070075,
    17.3060008021838740,
    17.1303053639168823,
    16.9546099256065865,
    16.7789144872535196,
    16.6032190488582501,
    16.4275236104213178,
    16.2518281719432416,
    16.0761327334245934,
    15.9004372948658954,
    15.7247418562676575,
    15.5490464176304393,
    15.3733509789547487,
    15.1976555402411186,
    15.0219601014900501,
    14.8462646627020458,
    14.6705692238776582,
    14.4948737850173597,
    14.3191783461216726,
    14.1434829071910926,
    13.9677874682261223,
    13.7920920292272378,
    13.6163965901949915,
    13.4407011511298258,
    13.2650057120322273,
    13.0893102729027202,
    12.9136148337417414,
    12.7379193945498077,
    12.5622239553273811,
    12.3865285160749146,
    12.2108330767929356,
    12.0351376374818582,
    11.8594421981421938,
    11.6837467587744008,
    11.5080513193789251,
    11.3323558799562480,
    11.1566604405068048,
    10.9809650010310911,
    10.8052695615295118,
    10.6295741220025644,
    10.4538786824506840,
    10.2781832428743236,
    10.1024878032739291,
     9.9267923636499500,
     9.7510969240028036,
     9.5754014843329589,
     9.3997060446408511,
     9.2240106049269261,
     9.0483151651916156,
     8.8726197254353369,
     8.6969242856585378,
     8.5212288458616516,
     8.3455334060451225,
     8.1698379662093412,
     7.9941425263547732,
     7.8184470864818199,
     7.6427516465909129,
     7.4670562066824919,
     7.2913607667569451,
     7.1156653268147050,
     6.9399698868562067,
     6.7642744468818581,
     6.5885790068920640,
     6.4128835668872570,
     6.2371881268678591,
     6.0614926868342485,
     5.8857972467868604,
     5.7101018067261027,
     5.5344063666523917,
     5.3587109265661379,
     5.1830154864677223,
     5.0073200463575747,
     4.8316246062361055,
     4.6559291661037081,
     4.4802337259607770,
     4.3045382858077428,
     4.1288428456450044,
     3.9531474054729383,
     3.7774519652919660,
     3.6017565251024850,
     3.4260610849048856,
     3.2503656446995768,
     3.0746702044869783,
     2.8989747642674457,
     2.7232793240414130,
     2.5475838838092479,
     2.3718884435713696,
     2.1961930033281623,
     2.0204975630800304,
     1.8448021228273697,
     1.6691066825705616,
     1.4934112423100003,
     1.3177158020461694,
     1.1420203617792850,
     0.9663249215098689,
     0.7906294812383031,
     0.6149340409649686,
     0.4392386006902348,
     0.2635431604145470,
     0.0878477201382483
  };
  setup_lat_hemisphere(N,lat,lon,DEG);
}

} // namespace reduced_gg
} // namespace grids
} // namespace atlas