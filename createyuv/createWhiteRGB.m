function aimRGB = createWhiteRGB(anHeight, anWidth)
%self explaining

    im = uint8(ones(anHeight, anWidth));
    ainRGB = cat(3, im, im , im);

end