function aF = extract_ReadYUV(astrYUVNewFileName, anIndx)
%self explaining

    %read yuv file
    fidYUVSingle = fopen([astrYUVNewFileName], 'rb');
    if(fidYUVSingle < 0)
        error('Problems in yuv file detected');
    end
    for nI = 0 : anIndx
        aF=fread(fidYUVSingle,176*144*1.5,'uchar');
    end
    fclose(fidYUVSingle);

end