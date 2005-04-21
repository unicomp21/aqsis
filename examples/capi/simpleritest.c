// simpleritest.cpp : Defines the entry point for the console application.
//

#include "ri.h"

/* Various color and point values used in the world */
RtColor colWhite = {1.0f, 1.0f, 1.0f};
RtPoint light1From = {2.0f, 6.0f, -3.0f};
RtPoint light1To = {0.0f, -1.0f, 0.0f};
RtPoint light2From = {-2.0f, 10.0f, 0.0f};
RtPoint light2To = {0.0f, 0.0f, 0.0f};
RtColor light3Col = {0.7f, 0.85f, 0.9f};
RtPoint light3From = {0.0f, 0.0f, -2.0f};
RtPoint light3To = {0.0f, 0.0f, 0.0f};
RtColor light4Col = {0.8f, 1.0f, 1.0f};
RtPoint light4From = {-4.0f, 6.0f, 0.0f};
RtPoint light4To = {-0.5f, -1.0f, 0.0f};
RtColor vaseCol = {0.5490f, 0.6745f, 0.4667f};
RtColor teapotCol = {0.8f, 0.8f, 0.8f};


/* The patch points for the vase object */
RtFloat p1[]  = {0.500000f,1.062500f,0.000000f,0.500000f,1.062500f,-0.114805f,0.434733f,1.062500f,-0.272374f,0.353554f,1.062500f,-0.353553f,0.429688f,1.006250f,0.000000f,0.429688f,1.006250f,-0.114805f,0.385015f,1.006250f,-0.222655f,0.303835f,1.006250f,-0.303835f,0.307276f,0.954832f,0.000000f,0.307276f,0.954832f,-0.060990f,0.260404f,0.954832f,-0.174150f,0.217277f,0.954832f,-0.217277f,0.265625f,0.875000f,0.000000f,0.265625f,0.875000f,-0.060990f,0.230952f,0.875000f,-0.144698f,0.187825f,0.875000f,-0.187825f};
RtFloat p2[]  = {0.500000f,1.062500f,0.000000f,0.429688f,1.006250f,0.000000f,0.307276f,0.954832f,0.000000f,0.265625f,0.875000f,0.000000f,0.500000f,1.062500f,0.114805f,0.429687f,1.006250f,0.114805f,0.307276f,0.954832f,0.060990f,0.265625f,0.875000f,0.060990f,0.434732f,1.062500f,0.272374f,0.385014f,1.006250f,0.222655f,0.260403f,0.954832f,0.174150f,0.230952f,0.875000f,0.144698f,0.353553f,1.062500f,0.353553f,0.303835f,1.006250f,0.303835f,0.217277f,0.954832f,0.217277f,0.187825f,0.875000f,0.187825f};
RtFloat p3[]  = {0.265625f,0.875000f,0.000000f,0.265625f,0.875000f,-0.060990f,0.230952f,0.875000f,-0.144698f,0.187825f,0.875000f,-0.187825f,0.240903f,0.827616f,0.000000f,0.240903f,0.827616f,-0.060990f,0.213470f,0.827616f,-0.127217f,0.170344f,0.827616f,-0.170344f,0.276993f,0.743071f,0.000000f,0.276993f,0.743071f,-0.071753f,0.246601f,0.743071f,-0.145126f,0.195863f,0.743071f,-0.195863f,0.312500f,0.703125f,0.000000f,0.312500f,0.703125f,-0.071753f,0.271708f,0.703125f,-0.170234f,0.220971f,0.703125f,-0.220971f};
RtFloat p4[]  = {0.265625f,0.875000f,0.000000f,0.240903f,0.827616f,0.000000f,0.276993f,0.743071f,0.000000f,0.312500f,0.703125f,0.000000f,0.265625f,0.875000f,0.060990f,0.240903f,0.827616f,0.060990f,0.276993f,0.743071f,0.071753f,0.312500f,0.703125f,0.071753f,0.230952f,0.875000f,0.144698f,0.213470f,0.827616f,0.127217f,0.246601f,0.743071f,0.145126f,0.271708f,0.703125f,0.170234f,0.187825f,0.875000f,0.187825f,0.170344f,0.827616f,0.170344f,0.195863f,0.743071f,0.195863f,0.220971f,0.703125f,0.220971f};
RtFloat p5[]  = {0.312500f,0.703125f,0.000000f,0.312500f,0.703125f,-0.071753f,0.271708f,0.703125f,-0.170234f,0.220971f,0.703125f,-0.220971f,0.394717f,0.610630f,0.000000f,0.394717f,0.610630f,-0.071753f,0.329845f,0.610631f,-0.228370f,0.279107f,0.610631f,-0.279107f,0.653216f,0.576236f,0.000000f,0.653216f,0.576236f,-0.147094f,0.565904f,0.576236f,-0.357882f,0.461893f,0.576236f,-0.461893f,0.640625f,0.453125f,0.000000f,0.640625f,0.453125f,-0.147094f,0.557001f,0.453125f,-0.348979f,0.452990f,0.453125f,-0.452990f};
RtFloat p6[]  = {0.312500f,0.703125f,0.000000f,0.394717f,0.610630f,0.000000f,0.653216f,0.576236f,0.000000f,0.640625f,0.453125f,0.000000f,0.312500f,0.703125f,0.071753f,0.394717f,0.610630f,0.071753f,0.653216f,0.576236f,0.147094f,0.640625f,0.453125f,0.147094f,0.271708f,0.703125f,0.170234f,0.329845f,0.610631f,0.228370f,0.565904f,0.576236f,0.357882f,0.557001f,0.453125f,0.348979f,0.220971f,0.703125f,0.220971f,0.279107f,0.610631f,0.279107f,0.461893f,0.576236f,0.461893f,0.452990f,0.453125f,0.452990f};
RtFloat p7[]  = {0.640625f,0.453125f,0.000000f,0.640625f,0.453125f,-0.147094f,0.557001f,0.453125f,-0.348979f,0.452990f,0.453125f,-0.452990f,0.603426f,0.089397f,0.000000f,0.603426f,0.089397f,-0.147094f,0.530697f,0.089397f,-0.322675f,0.426686f,0.089397f,-0.426686f,0.242728f,-0.313181f,0.000000f,0.242728f,-0.313181f,-0.039464f,0.199540f,-0.313181f,-0.143729f,0.171635f,-0.313181f,-0.171635f,0.171875f,-0.671875f,0.000000f,0.171875f,-0.671875f,-0.039464f,0.149439f,-0.671875f,-0.093629f,0.121534f,-0.671875f,-0.121534f};
RtFloat p8[]  = {0.640625f,0.453125f,0.000000f,0.603426f,0.089397f,0.000000f,0.242728f,-0.313181f,0.000000f,0.171875f,-0.671875f,0.000000f,0.640625f,0.453125f,0.147094f,0.603426f,0.089397f,0.147094f,0.242728f,-0.313181f,0.039464f,0.171875f,-0.671875f,0.039464f,0.557001f,0.453125f,0.348979f,0.530697f,0.089397f,0.322675f,0.199540f,-0.313181f,0.143729f,0.149439f,-0.671875f,0.093629f,0.452990f,0.453125f,0.452990f,0.426686f,0.089397f,0.426686f,0.171635f,-0.313181f,0.171635f,0.121534f,-0.671875f,0.121534f};
RtFloat p9[]  = {0.171875f,-0.671875f,0.000000f,0.171875f,-0.671875f,-0.039464f,0.149439f,-0.671875f,-0.093629f,0.121534f,-0.671875f,-0.121534f,0.156757f,-0.748412f,0.000000f,0.156757f,-0.748412f,-0.039464f,0.138749f,-0.748412f,-0.082938f,0.110844f,-0.748412f,-0.110844f,0.325000f,-0.770312f,0.000000f,0.325000f,-0.770312f,-0.089691f,0.293231f,-0.770312f,-0.166389f,0.229810f,-0.770312f,-0.229810f,0.390625f,-0.812500f,0.000000f,0.390625f,-0.812500f,-0.089691f,0.339635f,-0.812500f,-0.212793f,0.276214f,-0.812500f,-0.276214f};
RtFloat p10[] = {0.171875f,-0.671875f,0.000000f,0.156757f,-0.748412f,0.000000f,0.325000f,-0.770312f,0.000000f,0.390625f,-0.812500f,0.000000f,0.171875f,-0.671875f,0.039464f,0.156757f,-0.748412f,0.039464f,0.325000f,-0.770312f,0.089691f,0.390625f,-0.812500f,0.089691f,0.149439f,-0.671875f,0.093629f,0.138749f,-0.748412f,0.082938f,0.293231f,-0.770312f,0.166389f,0.339635f,-0.812500f,0.212793f,0.121534f,-0.671875f,0.121534f,0.110844f,-0.748412f,0.110844f,0.229810f,-0.770312f,0.229810f,0.276214f,-0.812500f,0.276214f};
RtFloat p11[] = {0.353553f,1.062500f,0.353553f,0.303835f,1.006250f,0.303835f,0.217277f,0.954832f,0.217277f,0.187825f,0.875000f,0.187825f,0.272374f,1.062500f,0.434732f,0.222655f,1.006250f,0.385014f,0.174150f,0.954832f,0.260403f,0.144698f,0.875000f,0.230952f,0.114805f,1.062500f,0.500000f,0.114805f,1.006250f,0.429688f,0.060990f,0.954832f,0.307276f,0.060990f,0.875000f,0.265625f,0.000000f,1.062500f,0.500000f,0.000000f,1.006250f,0.429688f,0.000000f,0.954832f,0.307276f,0.000000f,0.875000f,0.265625f};
RtFloat p12[] = {0.000000f,1.062500f,0.500000f,0.000000f,1.006250f,0.429688f,0.000000f,0.954832f,0.307276f,0.000000f,0.875000f,0.265625f,-0.114805f,1.062500f,0.500000f,-0.114805f,1.006250f,0.429688f,-0.060990f,0.954832f,0.307276f,-0.060990f,0.875000f,0.265625f,-0.272374f,1.062500f,0.434732f,-0.222655f,1.006250f,0.385014f,-0.174150f,0.954832f,0.260403f,-0.144698f,0.875000f,0.230952f,-0.353553f,1.062500f,0.353553f,-0.303835f,1.006250f,0.303835f,-0.217277f,0.954832f,0.217277f,-0.187825f,0.875000f,0.187825f};
RtFloat p13[] = {-0.353553f,1.062500f,0.353553f,-0.303835f,1.006250f,0.303835f,-0.217277f,0.954832f,0.217277f,-0.187825f,0.875000f,0.187825f,-0.434732f,1.062500f,0.272374f,-0.385014f,1.006250f,0.222655f,-0.260403f,0.954832f,0.174150f,-0.230952f,0.875000f,0.144698f,-0.500000f,1.062500f,0.114805f,-0.429688f,1.006250f,0.114805f,-0.307276f,0.954832f,0.060990f,-0.265625f,0.875000f,0.060990f,-0.500000f,1.062500f,0.000000f,-0.429688f,1.006250f,0.000000f,-0.307276f,0.954832f,0.000000f,-0.265625f,0.875000f,0.000000f};
RtFloat p14[] = {-0.500000f,1.062500f,0.000000f,-0.429688f,1.006250f,0.000000f,-0.307276f,0.954832f,0.000000f,-0.265625f,0.875000f,0.000000f,-0.500000f,1.062500f,-0.114805f,-0.429688f,1.006250f,-0.114805f,-0.307276f,0.954832f,-0.060990f,-0.265625f,0.875000f,-0.060990f,-0.434732f,1.062500f,-0.272374f,-0.385014f,1.006250f,-0.222655f,-0.260403f,0.954832f,-0.174150f,-0.230952f,0.875000f,-0.144698f,-0.353553f,1.062500f,-0.353553f,-0.303835f,1.006250f,-0.303835f,-0.217277f,0.954832f,-0.217277f,-0.187825f,0.875000f,-0.187825f};
RtFloat p15[] = {-0.353553f,1.062500f,-0.353553f,-0.303835f,1.006250f,-0.303835f,-0.217277f,0.954832f,-0.217277f,-0.187825f,0.875000f,-0.187825f,-0.272374f,1.062500f,-0.434732f,-0.222655f,1.006250f,-0.385014f,-0.174150f,0.954832f,-0.260403f,-0.144698f,0.875000f,-0.230952f,-0.114805f,1.062500f,-0.500000f,-0.114805f,1.006250f,-0.429688f,-0.060990f,0.954832f,-0.307276f,-0.060990f,0.875000f,-0.265625f,0.000000f,1.062500f,-0.500000f,0.000000f,1.006250f,-0.429688f,0.000000f,0.954832f,-0.307276f,0.000000f,0.875000f,-0.265625f};
RtFloat p16[] = {0.000000f,1.062500f,-0.500000f,0.000000f,1.006250f,-0.429688f,0.000000f,0.954832f,-0.307276f,0.000000f,0.875000f,-0.265625f,0.114805f,1.062500f,-0.500000f,0.114805f,1.006250f,-0.429688f,0.060990f,0.954832f,-0.307276f,0.060990f,0.875000f,-0.265625f,0.272374f,1.062500f,-0.434733f,0.222656f,1.006250f,-0.385014f,0.174150f,0.954832f,-0.260403f,0.144698f,0.875000f,-0.230952f,0.353554f,1.062500f,-0.353553f,0.303835f,1.006250f,-0.303835f,0.217277f,0.954832f,-0.217277f,0.187825f,0.875000f,-0.187825f};
RtFloat p17[] = {0.187825f,0.875000f,0.187825f,0.170344f,0.827616f,0.170344f,0.195863f,0.743071f,0.195863f,0.220971f,0.703125f,0.220971f,0.144698f,0.875000f,0.230952f,0.127217f,0.827616f,0.213470f,0.145126f,0.743071f,0.246601f,0.170234f,0.703125f,0.271708f,0.060990f,0.875000f,0.265625f,0.060990f,0.827616f,0.240903f,0.071753f,0.743071f,0.276993f,0.071753f,0.703125f,0.312500f,0.000000f,0.875000f,0.265625f,0.000000f,0.827616f,0.240903f,0.000000f,0.743071f,0.276993f,0.000000f,0.703125f,0.312500f};
RtFloat p18[] = {0.000000f,0.875000f,0.265625f,0.000000f,0.827616f,0.240903f,0.000000f,0.743071f,0.276993f,0.000000f,0.703125f,0.312500f,-0.060990f,0.875000f,0.265625f,-0.060990f,0.827616f,0.240903f,-0.071753f,0.743071f,0.276993f,-0.071753f,0.703125f,0.312500f,-0.144698f,0.875000f,0.230952f,-0.127217f,0.827616f,0.213470f,-0.145126f,0.743071f,0.246601f,-0.170234f,0.703125f,0.271708f,-0.187825f,0.875000f,0.187825f,-0.170344f,0.827616f,0.170344f,-0.195863f,0.743071f,0.195863f,-0.220971f,0.703125f,0.220971f};
RtFloat p19[] = {-0.187825f,0.875000f,0.187825f,-0.170344f,0.827616f,0.170344f,-0.195863f,0.743071f,0.195863f,-0.220971f,0.703125f,0.220971f,-0.230952f,0.875000f,0.144698f,-0.213470f,0.827616f,0.127217f,-0.246601f,0.743071f,0.145126f,-0.271708f,0.703125f,0.170234f,-0.265625f,0.875000f,0.060990f,-0.240903f,0.827616f,0.060990f,-0.276993f,0.743071f,0.071753f,-0.312500f,0.703125f,0.071753f,-0.265625f,0.875000f,0.000000f,-0.240903f,0.827616f,0.000000f,-0.276993f,0.743071f,0.000000f,-0.312500f,0.703125f,0.000000f};
RtFloat p20[] = {-0.265625f,0.875000f,0.000000f,-0.240903f,0.827616f,0.000000f,-0.276993f,0.743071f,0.000000f,-0.312500f,0.703125f,0.000000f,-0.265625f,0.875000f,-0.060990f,-0.240903f,0.827616f,-0.060990f,-0.276993f,0.743071f,-0.071753f,-0.312500f,0.703125f,-0.071753f,-0.230952f,0.875000f,-0.144698f,-0.213470f,0.827616f,-0.127217f,-0.246601f,0.743071f,-0.145126f,-0.271708f,0.703125f,-0.170234f,-0.187825f,0.875000f,-0.187825f,-0.170344f,0.827616f,-0.170344f,-0.195863f,0.743071f,-0.195863f,-0.220971f,0.703125f,-0.220971f};
RtFloat p21[] = {-0.187825f,0.875000f,-0.187825f,-0.170344f,0.827616f,-0.170344f,-0.195863f,0.743071f,-0.195863f,-0.220971f,0.703125f,-0.220971f,-0.144698f,0.875000f,-0.230952f,-0.127217f,0.827616f,-0.213470f,-0.145126f,0.743071f,-0.246601f,-0.170234f,0.703125f,-0.271708f,-0.060990f,0.875000f,-0.265625f,-0.060990f,0.827616f,-0.240903f,-0.071753f,0.743071f,-0.276993f,-0.071753f,0.703125f,-0.312500f,0.000000f,0.875000f,-0.265625f,0.000000f,0.827616f,-0.240903f,0.000000f,0.743071f,-0.276993f,0.000000f,0.703125f,-0.312500f};
RtFloat p22[] = {0.000000f,0.875000f,-0.265625f,0.000000f,0.827616f,-0.240903f,0.000000f,0.743071f,-0.276993f,0.000000f,0.703125f,-0.312500f,0.060990f,0.875000f,-0.265625f,0.060990f,0.827616f,-0.240903f,0.071753f,0.743071f,-0.276993f,0.071753f,0.703125f,-0.312500f,0.144698f,0.875000f,-0.230952f,0.127217f,0.827616f,-0.213470f,0.145126f,0.743071f,-0.246601f,0.170234f,0.703125f,-0.271708f,0.187825f,0.875000f,-0.187825f,0.170344f,0.827616f,-0.170344f,0.195863f,0.743071f,-0.195863f,0.220971f,0.703125f,-0.220971f};
RtFloat p23[] = {0.220971f,0.703125f,0.220971f,0.279107f,0.610631f,0.279107f,0.461893f,0.576236f,0.461893f,0.452990f,0.453125f,0.452990f,0.170234f,0.703125f,0.271708f,0.228370f,0.610631f,0.329845f,0.357882f,0.576236f,0.565904f,0.348979f,0.453125f,0.557001f,0.071753f,0.703125f,0.312500f,0.071753f,0.610630f,0.394717f,0.147094f,0.576236f,0.653216f,0.147094f,0.453125f,0.640625f,0.000000f,0.703125f,0.312500f,0.000000f,0.610630f,0.394717f,0.000000f,0.576236f,0.653216f,0.000000f,0.453125f,0.640625f};
RtFloat p24[] = {0.000000f,0.703125f,0.312500f,0.000000f,0.610630f,0.394717f,0.000000f,0.576236f,0.653216f,0.000000f,0.453125f,0.640625f,-0.071753f,0.703125f,0.312500f,-0.071753f,0.610630f,0.394717f,-0.147094f,0.576236f,0.653216f,-0.147094f,0.453125f,0.640625f,-0.170234f,0.703125f,0.271708f,-0.228370f,0.610631f,0.329845f,-0.357882f,0.576236f,0.565904f,-0.348979f,0.453125f,0.557001f,-0.220971f,0.703125f,0.220971f,-0.279107f,0.610631f,0.279107f,-0.461893f,0.576236f,0.461893f,-0.452990f,0.453125f,0.452990f};
RtFloat p25[] = {-0.220971f,0.703125f,0.220971f,-0.279107f,0.610631f,0.279107f,-0.461893f,0.576236f,0.461893f,-0.452990f,0.453125f,0.452990f,-0.271708f,0.703125f,0.170234f,-0.329845f,0.610631f,0.228370f,-0.565904f,0.576236f,0.357882f,-0.557001f,0.453125f,0.348979f,-0.312500f,0.703125f,0.071753f,-0.394717f,0.610630f,0.071753f,-0.653216f,0.576236f,0.147094f,-0.640625f,0.453125f,0.147094f,-0.312500f,0.703125f,0.000000f,-0.394717f,0.610630f,0.000000f,-0.653216f,0.576236f,0.000000f,-0.640625f,0.453125f,0.000000f};
RtFloat p26[] = {-0.312500f,0.703125f,0.000000f,-0.394717f,0.610630f,0.000000f,-0.653216f,0.576236f,0.000000f,-0.640625f,0.453125f,0.000000f,-0.312500f,0.703125f,-0.071753f,-0.394717f,0.610630f,-0.071753f,-0.653216f,0.576236f,-0.147094f,-0.640625f,0.453125f,-0.147094f,-0.271708f,0.703125f,-0.170234f,-0.329845f,0.610631f,-0.228370f,-0.565904f,0.576236f,-0.357882f,-0.557001f,0.453125f,-0.348979f,-0.220971f,0.703125f,-0.220971f,-0.279107f,0.610631f,-0.279107f,-0.461893f,0.576236f,-0.461893f,-0.452990f,0.453125f,-0.452990f};
RtFloat p27[] = {-0.220971f,0.703125f,-0.220971f,-0.279107f,0.610631f,-0.279107f,-0.461893f,0.576236f,-0.461893f,-0.452990f,0.453125f,-0.452990f,-0.170234f,0.703125f,-0.271708f,-0.228370f,0.610631f,-0.329845f,-0.357882f,0.576236f,-0.565904f,-0.348979f,0.453125f,-0.557001f,-0.071753f,0.703125f,-0.312500f,-0.071753f,0.610630f,-0.394717f,-0.147094f,0.576236f,-0.653216f,-0.147094f,0.453125f,-0.640625f,0.000000f,0.703125f,-0.312500f,0.000000f,0.610630f,-0.394717f,0.000000f,0.576236f,-0.653216f,0.000000f,0.453125f,-0.640625f};
RtFloat p28[] = {0.000000f,0.703125f,-0.312500f,0.000000f,0.610630f,-0.394717f,0.000000f,0.576236f,-0.653216f,0.000000f,0.453125f,-0.640625f,0.071753f,0.703125f,-0.312500f,0.071753f,0.610630f,-0.394717f,0.147094f,0.576236f,-0.653216f,0.147094f,0.453125f,-0.640625f,0.170234f,0.703125f,-0.271708f,0.228370f,0.610631f,-0.329845f,0.357882f,0.576236f,-0.565904f,0.348979f,0.453125f,-0.557001f,0.220971f,0.703125f,-0.220971f,0.279107f,0.610631f,-0.279107f,0.461893f,0.576236f,-0.461893f,0.452990f,0.453125f,-0.452990f};
RtFloat p29[] = {0.452990f,0.453125f,0.452990f,0.426686f,0.089397f,0.426686f,0.171635f,-0.313181f,0.171635f,0.121534f,-0.671875f,0.121534f,0.348979f,0.453125f,0.557001f,0.322675f,0.089397f,0.530697f,0.143729f,-0.313181f,0.199540f,0.093629f,-0.671875f,0.149439f,0.147094f,0.453125f, 0.640625f,0.147094f,0.089397f,0.603426f,0.039464f,-0.313181f,0.242728f,0.039464f,-0.671875f,0.171875f,0.000000f,0.453125f,0.640625f,0.000000f,0.089397f,0.603426f,0.000000f,-0.313181f,0.242728f,0.000000f,-0.671875f,0.171875f};
RtFloat p30[] = {0.000000f,0.453125f,0.640625f,0.000000f,0.089397f,0.603426f,0.000000f,-0.313181f,0.242728f,0.000000f,-0.671875f,0.171875f,-0.147094f,0.453125f,0.640625f,-0.147094f,0.089397f,0.603426f,-0.039464f,-0.313181f,0.242728f,-0.039464f,-0.671875f,0.171875f,-0.348979f,0.453125f,0.557001f,-0.322675f,0.089397f,0.530697f,-0.143729f,-0.313181f,0.199540f,-0.093629f,-0.671875f,0.149439f,-0.452990f,0.453125f,0.452990f,-0.426686f,0.089397f,0.426686f,-0.171635f,-0.313181f,0.171635f,-0.121534f,-0.671875f,0.121534f};
RtFloat p31[] = {-0.452990f,0.453125f,0.452990f,-0.426686f,0.089397f,0.426686f,-0.171635f,-0.313181f,0.171635f,-0.121534f,-0.671875f,0.121534f,-0.557001f,0.453125f,0.348979f,-0.530697f,0.089397f,0.322675f,-0.199540f,-0.313181f,0.143729f,-0.149439f,-0.671875f,0.093629f,-0.640625f,0.453125f,0.147094f,-0.603426f,0.089397f,0.147094f,-0.242728f,-0.313181f,0.039464f,-0.171875f,-0.671875f,0.039464f,-0.640625f,0.453125f,0.000000f,-0.603426f,0.089397f,0.000000f,-0.242728f,-0.313181f,0.000000f,-0.171875f,-0.671875f,0.000000f};
RtFloat p32[] = {-0.640625f,0.453125f,0.000000f,-0.603426f,0.089397f,0.000000f,-0.242728f,-0.313181f,0.000000f,-0.171875f,-0.671875f,0.000000f,-0.640625f,0.453125f,-0.147094f,-0.603426f,0.089397f,-0.147094f,-0.242728f,-0.313181f,-0.039464f,-0.171875f,-0.671875f,-0.039464f,-0.557001f,0.453125f,-0.348979f,-0.530697f,0.089397f,-0.322675f,-0.199540f,-0.313181f,-0.143729f,-0.149439f,-0.671875f,-0.093629f,-0.452990f,0.453125f,-0.452990f,-0.426686f,0.089397f,-0.426686f,-0.171635f,-0.313181f,-0.171635f,-0.121534f,-0.671875f,-0.121534f};
RtFloat p33[] = {-0.452990f,0.453125f,-0.452990f,-0.426686f,0.089397f,-0.426686f,-0.171635f,-0.313181f,-0.171635f,-0.121534f,-0.671875f,-0.121534f,-0.348979f,0.453125f,-0.557001f,-0.322675f,0.089397f,-0.530697f,-0.143729f,-0.313181f,-0.199540f,-0.093629f,-0.671875f,-0.149439f,-0.147094f,0.453125f,-0.640625f,-0.147094f,0.089397f,-0.603426f,-0.039464f,-0.313181f,-0.242728f,-0.039464f,-0.671875f,-0.171875f,0.000000f,0.453125f,-0.640625f,0.000000f,0.089397f,-0.603426f,0.000000f,-0.313181f,-0.242728f,0.000000f,-0.671875f,-0.171875f};
RtFloat p34[] = {0.000000f,0.453125f,-0.640625f,0.000000f,0.089397f,-0.603426f,0.000000f,-0.313181f,-0.242728f,0.000000f,-0.671875f,-0.171875f,0.147094f,0.453125f,-0.640625f,0.147094f,0.089397f,-0.603426f,0.039464f,-0.313181f,-0.242728f,0.039464f,-0.671875f,-0.171875f,0.348979f,0.453125f,-0.557001f,0.322675f,0.089397f,-0.530697f,0.143729f,-0.313181f,-0.199540f,0.093629f,-0.671875f,-0.149439f,0.452990f,0.453125f,-0.452990f,0.426686f,0.089397f,-0.426686f,0.171635f,-0.313181f,-0.171635f,0.121534f,-0.671875f,-0.121534f};
RtFloat p35[] = {0.121534f,-0.671875f,0.121534f,0.110844f,-0.748412f,0.110844f,0.229810f,-0.770312f,0.229810f,0.276214f,-0.812500f,0.276214f,0.093629f,-0.671875f,0.149439f,0.082938f,-0.748412f,0.138749f,0.166389f,-0.770312f,0.293231f,0.212793f,-0.812500f,0.339635f,0.039464f,-0.671875f,0.171875f,0.039464f,-0.748412f,0.156757f,0.089691f,-0.770312f,0.325000f,0.089691f,-0.812500f,0.390625f,0.000000f,-0.671875f,0.171875f,0.000000f,-0.748412f,0.156757f,0.000000f,-0.770312f,0.325000f,0.000000f,-0.812500f,0.390625f};
RtFloat p36[] = {0.000000f,-0.671875f,0.171875f,0.000000f,-0.748412f,0.156757f,0.000000f,-0.770312f,0.325000f,0.000000f,-0.812500f,0.390625f,-0.039464f,-0.671875f,0.171875f,-0.039464f,-0.748412f,0.156757f,-0.089691f,-0.770312f,0.325000f,-0.089691f,-0.812500f,0.390625f,-0.093629f,-0.671875f,0.149439f,-0.082938f,-0.748412f,0.138749f,-0.166389f,-0.770312f,0.293231f,-0.212793f,-0.812500f,0.339635f,-0.121534f,-0.671875f,0.121534f,-0.110844f,-0.748412f,0.110844f,-0.229810f,-0.770312f,0.229810f,-0.276214f,-0.812500f,0.276214f};
RtFloat p37[] = {0.121534f,-0.671875f,0.121534f,-0.110844f,-0.748412f,0.110844f,-0.229810f,-0.770312f,0.229810f,-0.276214f,-0.812500f,0.276214f,-0.149439f,-0.671875f,0.093629f,-0.138749f,-0.748412f,0.082938f,-0.293231f,-0.770312f,0.166389f,-0.339635f,-0.812500f,0.212793f,-0.171875f,-0.671875f,0.039464f,-0.156757f,-0.748412f,0.039464f,-0.325000f,-0.770312f,0.089691f,-0.390625f,-0.812500f,0.089691f,-0.171875f,-0.671875f,0.000000f,-0.156757f,-0.748412f,0.000000f,-0.325000f,-0.770312f,0.000000f,-0.390625f,-0.812500f,0.000000f};
RtFloat p38[] = {-0.171875f,-0.671875f,0.000000f,-0.156757f,-0.748412f,0.000000f,-0.325000f,-0.770312f,0.000000f,-0.390625f,-0.812500f,0.000000f,-0.171875f,-0.671875f,-0.039464f,-0.156757f,-0.748412f,-0.039464f,-0.325000f,-0.770312f,-0.089691f,-0.390625f,-0.812500f,-0.089691f,-0.149439f,-0.671875f,-0.093629f,-0.138749f,-0.748412f,-0.082938f,-0.293231f,-0.770312f,-0.166389f,-0.339635f,-0.812500f,-0.212793f,-0.121534f,-0.671875f,-0.121534f,-0.110844f,-0.748412f,-0.110844f,-0.229810f,-0.770312f,-0.229810f,-0.276214f,-0.812500f,-0.276214f};
RtFloat p39[] = {-0.121534f,-0.671875f,-0.121534f,-0.110844f,-0.748412f,-0.110844f,-0.229810f,-0.770312f,-0.229810f,-0.276214f,-0.812500f,-0.276214f,-0.093629f,-0.671875f,-0.149439f,-0.082938f,-0.748412f,-0.138749f,-0.166389f,-0.770312f,-0.293231f,-0.212793f,-0.812500f,-0.339635f,-0.039464f,-0.671875f,-0.171875f,-0.039464f,-0.748412f,-0.156757f,-0.089691f,-0.770312f,-0.325000f,-0.089691f,-0.812500f,-0.390625f,0.000000f,-0.671875f,-0.171875f,0.000000f,-0.748412f,-0.156757f,0.000000f,-0.770312f,-0.325000f,0.000000f,-0.812500f,-0.390625f};
RtFloat p40[] = {0.000000f,-0.671875f,-0.171875f,0.000000f,-0.748412f,-0.156757f,0.000000f,-0.770312f,-0.325000f,0.000000f,-0.812500f,-0.390625f,0.039464f,-0.671875f,-0.171875f,0.039464f,-0.748412f,-0.156757f,0.089691f,-0.770312f,-0.325000f,0.089691f,-0.812500f,-0.390625f,0.093629f,-0.671875f,-0.149439f,0.082938f,-0.748412f,-0.138749f,0.166389f,-0.770312f,-0.293231f,0.212793f,-0.812500f,-0.339635f,0.121534f,-0.671875f,-0.121534f,0.110844f,-0.748412f,-0.110844f,0.229810f,-0.770312f,-0.229810f,0.276214f,-0.812500f,-0.276214f};

/* The patch point data for the backdrop and floor */
RtFloat p41[] = { -1.0f, 0.0f, -1.0f, -0.5f, 0.0f, -1.0f, 0.5f, 0.0f, -1.0f, 1.0f, 0.0f, -1.0f, -1.0f, 0.0f, -0.75f, -0.5f, 0.0f, -0.75f, 0.5f, 0.0f, -0.75f, 1.0f, 0.0f, -0.75f, -1.0f, 0.0f, -0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f, -0.5f, 1.0f, 0.0f, -0.5f, -1.0f, 0.0f, 0.0f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0};
RtFloat p42[] = { -1.0f, 0.0f, 0.0f, -0.5f, 0.0f, 0.0f, 0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, -1.0f, 0.0f, 1.0f, -0.5f, 0.0f, 1.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 1.0f, -0.5f, 0.0f, 1.0f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 1.0f, -1.0f, 1.0f, 1.0f, -0.5f, 1.0f, 1.0f, 0.5f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0};

/* Light source parameters */
RtFloat l0intensity = 0.2f;
RtFloat l1intensity = 20.0f;
RtFloat l1coneangle = 0.35f;
RtFloat l1conedeltaangle = 0.01f;
RtString shadowname1 = "shad1.map";
RtFloat l2intensity = 0.4f;
RtFloat l3intensity = 0.3f;
RtFloat l4intensity = 10.0f;
RtFloat l4coneangle = 0.3f;
RtFloat l4conedeltaangle = 0.01f;
RtString shadowname2 = "shad2.map";

/* Camera field of view */
RtFloat fov = 37.0f;
RtFloat shad1fov = 40.11f;
RtFloat shad2fov = 34.38f;

/* Hider depth filter type */
RtString dfilt = "midpoint";

/* Shader parameters */
RtFloat Ka = 0.4f;
RtFloat Kd = 1.0f;

RtFloat dispsphere = 0.2f;
RtFloat Km = 4.0f;
RtFloat Ks = 1.5f;
RtFloat roughness = 1.0f;



void CreateScene()
{
	/* Vase */
	RiAttributeBegin();
		RiColor(vaseCol);
		RiSurface("matte", "Ka", &Ka, "Kd", &Kd, RI_NULL);
		RiTransformBegin();
			RiTranslate(-0.4f, 0.0f, 0.0f);
			RiBasis(RiBezierBasis, 3, RiBezierBasis, 3);
			RiPatch(RI_BICUBIC, RI_P, &p1, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p2, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p3, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p4, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p5, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p6, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p7, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p8, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p9, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p10, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p11, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p12, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p13, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p14, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p15, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p16, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p17, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p18, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p19, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p20, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p21, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p22, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p23, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p24, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p25, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p26, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p27, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p28, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p29, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p30, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p31, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p32, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p33, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p34, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p35, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p36, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p37, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p38, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p39, RI_NULL);
			RiPatch(RI_BICUBIC, RI_P, &p40, RI_NULL);
		RiTransformEnd();
	RiAttributeEnd();

	/* Backdrop and base */
	RiAttributeBegin();
		RiTranslate(0.0f, -0.811875f, 0.0f);
		RiScale(5.0f, 5.0f, 5.0f);
		RiSurface("matte", RI_NULL);

		RiPatch(RI_BICUBIC, RI_P, p41, RI_NULL); 
		RiPatch(RI_BICUBIC, RI_P, p42, RI_NULL); 
	RiAttributeEnd();

	/* Teapot */
	RiAttributeBegin();
		RiAttribute("displacementbound", "sphere", &dispsphere, RI_NULL);
		RiDeclare("Km", "uniform float");
		RiDisplacement("dented", "Km", &Km, RI_NULL);
		RiSurface("metal", "Ks", &Ks, "roughness", &roughness, RI_NULL);
		RiOrientation(RI_LH);
		RiColor(teapotCol);
		RiTranslate(1.0f, -0.8f, 1.0f);
		RiRotate(50.0f, 0.0f, 1.0f, 0.0f);
		RiRotate(-90.0f, 1.0f, 0.0f, 0.0f); 
		RiScale(0.5f, 0.5f, 0.5f);
		RiGeometry("teapot", RI_NULL);
	RiAttributeEnd();
}


int main(int argc, char* argv[])
{
	RtString shaderpath = "..\\..\\shaders:&";
	RtString displaypath = "..\\..\\bin:&";

	/* Initialise the renderer */
	RiBegin(0);

	/* Make sure the renderer can find the stuff it needs, i.e. shaders and displays */
	RiOption("searchpath", "shader", &shaderpath, RI_NULL);
	RiOption("searchpath", "display", &displaypath, RI_NULL);

	/* Mark the start of the first shadow frame */
	RiFrameBegin(1);

		RiDisplay("shad1.map", "shadow", RI_Z, RI_NULL);
		RiHider(RI_HIDDEN, "depthfilter", &dfilt, RI_NULL);

		RiFormat(256, 256, 1.0f);
		RiPixelSamples(1, 1);
		RiPixelFilter(RiBoxFilter, 1.0f, 1.0f);
		RiShadingRate(4.0f);

		RiProjection(RI_PERSPECTIVE, "fov", &shad1fov, RI_NULL);
		RiRotate(-62.75f, 1.0f, 0.0f, 0.0f);
		RiRotate(33.69f, 0.0f, 1.0f, 0.0f);
		RiTranslate(-2.0f, -6.0f, 3.0f);
	
		RiWorldBegin();

			CreateScene();

		RiWorldEnd();

	RiFrameEnd(); /* 1 */

	/* Mark the start of the second shadow frame */
	RiFrameBegin(2);

		RiDisplay("shad2.map", "shadow", RI_Z, RI_NULL);
		RiHider(RI_HIDDEN, "depthfilter", &dfilt, RI_NULL);

		RiFormat(256, 256, 1.0f);
		RiPixelSamples(1, 1);
		RiPixelFilter(RiBoxFilter, 1.0f, 1.0f);
		RiShadingRate(4.0f);

		RiProjection(RI_PERSPECTIVE, "fov", &shad2fov, RI_NULL);
		RiRotate(-63.43f, 1.0f, 0.0f, 0.0f);
		RiRotate(-90.00f, 0.0f, 1.0f, 0.0f);
		RiTranslate(4.0f, -6.0f, 0.0f);
	
		RiWorldBegin();

			CreateScene();

		RiWorldEnd();

	RiFrameEnd(); /* 2 */


	/* Now render the beauty pass */
	RiFrameBegin(3);

		RiDisplay("vase.tif", RI_FILE, RI_RGBA, RI_NULL);

		RiFormat(256, 192, 1.0f);
		RiPixelSamples(4, 4);
		RiPixelFilter(RiCatmullRomFilter, 3.0f, 3.0f);
		RiShadingRate(1.0f);
		RiProjection(RI_PERSPECTIVE, RI_FOV, &fov, RI_NULL);
	
		RiRotate(-18.4214f, 1.0f, 0.0f, 0.0f);
		RiTranslate(0.0f, -1.8850f, 4.7600f);

		RiSides(2);
		RiOrientation(RI_RH);

		RiDeclare("shadowname", "uniform string");

		RiWorldBegin();

			/* Setup the lights */
			RiLightSource("ambientlight", "intensity", &l0intensity, RI_NULL);
			RiLightSource("shadowspot", "intensity", &l1intensity, "lightcolor", &colWhite, "from", &light1From, "to", &light1To, "coneangle", &l1coneangle, "conedeltaangle", &l1conedeltaangle, "shadowname", &shadowname1, RI_NULL);
			RiLightSource("distantlight", "intensity", &l2intensity, "lightcolor", &colWhite, "from", &light2From, "to", &light2To, RI_NULL);
			RiLightSource("distantlight", "intensity", &l3intensity, "lightcolor", &light3Col, "from", &light3From, "to", &light3To, RI_NULL);
			RiLightSource("shadowspot", "intensity", &l4intensity, "lightcolor", &light4Col, "from", &light4From, "to", &light4To, "coneangle", &l4coneangle, "conedeltaangle", &l4conedeltaangle, "shadowname", &shadowname2, RI_NULL);

			CreateScene();

		RiWorldEnd();
	RiFrameEnd();

	RiEnd();

	return 0;
}
