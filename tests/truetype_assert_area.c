#include <stdio.h>

#define STB_TRUETYPE_IMPLEMENTATION
#include "stb_truetype.h"

// Test via loading the font.
#if 0
unsigned char ttf_buffer[1 << 25];
int main2(int argc, char **argv) {
  stbtt_fontinfo font;
  // "Exedore Laser Italic" http://iconian.com/e.html
  // (In http://iconian.com/fonts/exedore.zip)
  fread(ttf_buffer, 1, 1<<25, fopen("exedoreli.ttf", "rb"));
  stbtt_InitFont(&font, ttf_buffer, 0);

  int width, height, xoff, yoff;
  (void)stbtt_GetCodepointBitmapSubpixel(&font,
                                         0.4972374737262726,
                                         0.4986416995525360,
                                         0.2391788959503174,
                                         0.1752119064331055,
                                         'd',
                                         &width, &height,
                                         &xoff, &yoff);

  printf("OK.\n");
  return 0;
}
#endif

// Direct standalone test of rasterizing.
stbtt__edge edges[48] = {
  {358.74740601,-364.83050537,  370.35867310,-364.54614258,  1,},
  {91.23363495,-364.83050537,  66.86900330,-267.09674072,  0,},
  {370.35867310,-364.54614258,  381.07647705,-363.69299316,  1,},
  {381.07647705,-363.69299316,  390.90078735,-362.27108765,  1,},
  {390.90078735,-362.27108765,  399.83163452,-360.28039551,  1,},
  {399.83163452,-360.28039551,  407.86901855,-357.72097778,  1,},
  {407.86901855,-357.72097778,  415.01293945,-354.59277344,  1,},
  {415.01293945,-354.59277344,  421.26336670,-350.89581299,  1,},
  {421.26336670,-350.89581299,  426.62030029,-346.63009644,  1,},
  {426.62030029,-346.63009644,  431.08380127,-341.79559326,  1,},
  {431.08380127,-341.79559326,  434.65380859,-336.39236450,  1,},
  {434.65380859,-336.39236450,  437.33035278,-330.42034912,  1,},
  {437.33035278,-330.42034912,  439.11340332,-323.87957764,  1,},
  {439.11340332,-323.87957764,  440.00299072,-316.77001953,  1,},
  {440.00299072,-316.77001953,  439.99911499,-309.09170532,  1,},
  {439.99911499,-309.09170532,  439.10174561,-300.84466553,  1,},
  {439.10174561,-300.84466553,  437.31091309,-292.02883911,  1,},
  {437.31091309,-292.02883911,  431.34405518,-267.09674072,  1,},
  {285.65350342,-268.09402466,  294.60375977,-267.59536743,  0,},
  {164.32754517,-268.09402466,  164.32754517,-267.09674072,  1,},
  {294.60375977,-267.59536743,  303.05679321,-267.09674072,  0,},
  {418.91314697,-218.72850037,  382.61480713,-72.62647247,  1,},
  {321.95181274,-218.72850037,  298.08441162,-121.49336243,  0,},
  {298.08441162,-121.49336243,  295.92456055,-115.76677704,  0,},
  {295.92456055,-115.76677704,  292.42834473,-110.80373383,  0,},
  {292.42834473,-110.80373383,  287.59582520,-106.60423279,  0,},
  {287.59582520,-106.60423279,  281.42697144,-103.16828156,  0,},
  {281.42697144,-103.16828156,  273.92178345,-100.49587250,  0,},
  {273.92178345,-100.49587250,  265.08029175,-98.58701324,  0,},
  {265.08029175,-98.58701324,  254.90246582,-97.44168854,  0,},
  {254.90246582,-97.44168854,  243.38830566,-97.05992126,  0,},
  {25.10105324,-97.05992126,  0.73641634,0.17521191,  0,},
  {382.61480713,-72.62647247,  380.06838989,-63.81064606,  1,},
  {380.06838989,-63.81064606,  376.90432739,-55.56357956,  1,},
  {376.90432739,-55.56357956,  373.12261963,-47.88527679,  1,},
  {373.12261963,-47.88527679,  368.72323608,-40.77573776,  1,},
  {368.72323608,-40.77573776,  363.70617676,-34.23496246,  1,},
  {363.70617676,-34.23496246,  358.07147217,-28.26294708,  1,},
  {358.07147217,-28.26294708,  351.81909180,-22.85969734,  1,},
  {351.81909180,-22.85969734,  344.94906616,-18.02520943,  1,},
  {344.94906616,-18.02520943,  337.46136475,-13.75948620,  1,},
  {337.46136475,-13.75948620,  329.35598755,-10.06252575,  1,},
  {329.35598755,-10.06252575,  320.63296509,-6.93432808,  1,},
  {320.63296509,-6.93432808,  311.29229736,-4.37489367,  1,},
  {311.29229736,-4.37489367,  301.33395386,-2.38422251,  1,},
  {301.33395386,-2.38422251,  290.75793457,-0.96231449,  1,},
  {290.75793457,-0.96231449,  279.56427002,-0.10916968,  1,},
  {279.56427002,-0.10916968,  267.75292969,0.17521191,  1,},
};

int main(int argc, char **argv) {
  stbtt__bitmap bm;

  bm.w = 456;
  bm.h = 366;
  bm.stride = 456;
  bm.pixels = (unsigned char*) malloc (456 * 366);

  stbtt__rasterize_sorted_edges(&bm, edges, 48, 1, 0, -365, 0);

  printf("OK\n");
  return 0;
}
