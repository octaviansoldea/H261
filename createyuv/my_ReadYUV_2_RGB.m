function aRGB = my_ReadYUV_2_RGB(astrYUVFileName)
%self explaining

    %read yuv file
    fidYUVSingle = fopen([astrYUVFileName], 'rb');
    f=fread(fidYUVSingle,176*144*1.5,'uchar');
    fclose(fidYUVSingle);
   
    aRGB = my_YUV_2_RGB(f);

end