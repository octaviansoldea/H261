function aYUV_4Dump = im2YUV_4Dump(aIm)
%This function receives an rgb image aIm in the input and translates it
%into a yuv dumpable image in CIF or QCIF format

    %imCIF_OR_QCIF=double(imresize(aIm,[144 176],'bilinear'));
    [nHeight nWidth nColsNr] = size(aIm);
    im_CIF_OR_QCIF = double(aIm);
    imY=uint8(0.1280*im_CIF_OR_QCIF(:,:,1)+0.5211*im_CIF_OR_QCIF(:,:,2)+0.2100*im_CIF_OR_QCIF(:,:,3)+16);                        
    Ref2=imresize(im_CIF_OR_QCIF,0.5);
    imU=uint8(0.5332*Ref2(:,:,1)-0.3800*Ref2(:,:,2)-0.1532*Ref2(:,:,3)+128);
    imV=uint8(-0.0739*Ref2(:,:,1)-0.3007*Ref2(:,:,2)+0.3746*Ref2(:,:,3)+128);
    nPixelsNr = nHeight * nWidth;
    aYUV_4Dump=[reshape(imY',1,nPixelsNr) reshape(imV',1,nPixelsNr/4) reshape(imU',1,nPixelsNr/4)];
       
end