CREATE TABLE FeatureData
 (
   ImageId                    int unsigned     not null  references Images(ImageId),
   SipperFileId               int unsigned     not null  references SipperFiles(SipperFileId),
   Size                       float default null,
   Moment1                    float default null,
   Moment2                    float default null,
   Moment3                    float default null,
   Moment4                    float default null,
   Moment5                    float default null,
   Moment6                    float default null,
   Moment7                    float default null,
   EdgeSize                   float default null,
   EdgeMoment1                float default null,
   EdgeMoment2                float default null,
   EdgeMoment3                float default null,
   EdgeMoment4                float default null,
   EdgeMoment5                float default null,
   EdgeMoment6                float default null,
   EdgeMoment7                float default null,
   TransparancyConvexHull     float default null,
   TransparancyPixelCount     float default null,
   TransparancyOpen3          float default null,
   TransparancyOpen5          float default null,
   TransparancyOpen7          float default null,
   TransparancyOpen9          float default null,
   TransparancyClose3         float default null,
   TransparancyClose5         float default null,
   TransparancyClose7         float default null,
   EigenRatio                 float default null,
   EigenHead                  float default null,
   ConvexArea                 float default null,
   TransparancySize           float default null,
   TransparancyWtd            float default null,
   WeighedMoment0             float default null,
   WeighedMoment1             float default null,
   WeighedMoment2             float default null,
   WeighedMoment3             float default null,
   WeighedMoment4             float default null,
   WeighedMoment5             float default null,
   WeighedMoment6             float default null,
   WeighedMoment7             float default null,
   Fourier0                   float default null,
   Fourier1                   float default null,
   Fourier2                   float default null,
   Fourier3                   float default null,
   Fourier4                   float default null,
   ContourFourierDescriptor0  float default null,
   ContourFourierDescriptor1  float default null,
   ContourFourierDescriptor2  float default null,
   ContourFourierDescriptor3  float default null,
   ContourFourierDescriptor4  float default null,
   FourierDescRight1          float default null,
   FourierDescLeft2           float default null,
   FourierDescRight2          float default null,
   FourierDescLeft3           float default null,
   FourierDescRight3          float default null,
   FourierDescLeft4           float default null,
   FourierDescRight4          float default null,
   FourierDescLeft5           float default null,
   FourierDescRight5          float default null,
   FourierDescLeft6           float default null,
   FourierDescRight6          float default null,
   FourierDescLeft7           float default null,
   FourierDescRight7          float default null,
   FourierDescLeft8           float default null,
   FourierDescRight8          float default null,
   IntensityHist1             float default null,
   IntensityHist2             float default null,
   IntensityHist3             float default null,
   IntensityHist4             float default null,
   IntensityHist5             float default null,
   IntensityHist6             float default null,
   IntensityHist7             float default null,
   HeightVsWidth              float default null,
   Length                     float default null,
   Width                      float default null,
   FilledArea                 float default null,
   FlowRate1                  float default null,
   FlowRate2                  float default null,
   IntensityHistB0            float default null,
   IntensityHistB1            float default null,
   IntensityHistB2            float default null,
   IntensityHistB3            float default null,
   IntensityHistB4            float default null,
   IntensityHistB5            float default null,
   IntensityHistB6            float default null,
   IntensityHistB7            float default null,
   Depth                      float default null,
   Salinity                   float default null,
   Oxygen                     float default null,
   Florences                  float default null,

   PRIMARY KEY        (ImageId  asc),
   KEY SipperFileKey  (SipperFileId  asc, ImageId  asc),
   foreign key (ImageId) references Images (ImageId),
   foreign key (SipperFileId) references SipperFiles (SipperFileId)
   
);




