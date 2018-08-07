# Pattern recognition in 3D point clouds using 2D lidar

This project is my master's thesis, successfully defended in 2017. Full text in Russian is attached.

## General idea
Let's assume that we have 2D lidar, which allows to get distance to obstacles only in one plane, but we want to make full 3D point cloud. This goal can be achieved if we perform scan in one plane, then turn lidar a little and perform another scan, and so on. As a result we will get an array of values in spherical coordinate system, each value represents distance to obstacle with two angles between the obstacle and center of lidar and horizon respectfully. We can see something like that:

This image is shifted a little to reveal volume. Each yellow dot is a single lidar measurement.

As a raw point cloud this information is not very valuable. What could be extracted from it? We can try to find some patterns, basic geometric shapes, for example. Raw point cloud is converted to a monochrome image, where intensity of each pixel represents distance to an obstacle. Then we can apply any pattern regognition algorythm.
