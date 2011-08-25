function aimRGB = createBlackRGB(anHeight, anWidth)
%self explaining

    im = uint8(zeros(anHeight, anWidth));
    aimRGB = cat(3, im, im , im);

end