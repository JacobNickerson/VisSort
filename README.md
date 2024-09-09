<!-- Improved compatibility of back to top link: See: https://github.com/othneildrew/Best-README-Template/pull/73 -->
<a id="readme-top"></a>
<!--
*** Thanks for checking out the Best-README-Template. If you have a suggestion
*** that would make this better, please fork the repo and create a pull request
*** or simply open an issue with the tag "enhancement".
*** Don't forget to give the project a star!
*** Thanks again! Now go create something AMAZING! :D
-->



<!-- PROJECT SHIELDS -->
<!--
*** I'm using markdown "reference style" links for readability.
*** Reference links are enclosed in brackets [ ] instead of parentheses ( ).
*** See the bottom of this document for the declaration of the reference variables
*** for contributors-url, forks-url, etc. This is an optional, concise syntax you may use.
*** https://www.markdownguide.org/basic-syntax/#reference-style-links
-->
[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![Issues][issues-shield]][issues-url]
[![MIT License][license-shield]][license-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />

<h3 align="center">VisSort</h3>

  <p align="center">
    Sorting Algorithm Visualizer 
    <br />
    <br />
    <a href="https://github.com/JacobNickerson/VisSort">View Demo</a>
    ·
    <a href="https://github.com/JacobNickerson/VisSort/issues/new?labels=bug&template=bug-report---.md">Report Bug</a>
    ·
    <a href="https://github.com/JacobNickerson/VisSort/issues/new?labels=enhancement&template=feature-request---.md">Request Feature</a>
  </p>
</div>



<!-- TABLE OF CONTENTS -->
<details>
  <summary>Table of Contents</summary>
  <ol>
    <li>
      <a href="#about-the-project">About The Project</a>
      <ul>
        <li><a href="#built-with">Built With</a></li>
      </ul>
    </li>
    <li>
      <a href="#getting-started">Getting Started</a>
      <ul>
        <li><a href="#prerequisites">Prerequisites</a></li>
        <li><a href="#installation">Installation</a></li>
      </ul>
    </li>
    <li><a href="#usage">Usage</a></li>
    <li><a href="#roadmap">Roadmap</a></li>
    <li><a href="#contributing">Contributing</a></li>
    <li><a href="#license">License</a></li>
    <li><a href="#contact">Contact</a></li>
    <li><a href="#acknowledgments">Acknowledgments</a></li>
  </ol>
</details>



<!-- ABOUT THE PROJECT -->
## About The Project

[![Product Name Screen Shot][product-screenshot]](images/screenshot.png)

A small SFML application used to visualize various sorting algorithms! Currently supporting bubbleSort, mergeSort, quickSort, insertionSort, selectionSort, and bogoSort.
See how sorting algorithms work in real time as VisSort highlights which data points are being compared or operated on.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



### Built With

* [![C++][Isocpp.org]][C++-url]
* [![SFML][SFML-dev.org]][SFML-url]

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- GETTING STARTED -->
## Getting Started
To get a local copy up and running follow these simple example steps.

### Prerequisites

* WSL
  ```sh
  wsl --install
  ```
VisSort was built using WSL (Ubuntu 22.04.2 LTS on Windows 10 x86_64). Your version may
    differ slightly, but should likely work so long as you have the `apt-get`
    package manager.
### Installation
1. Clone the repo
   ```sh
   git clone https://github.com/JacobNickerson/VisSort.git
   ```
2. Update apt
   ```sh
   sudo apt update
   sudo apt upgrade
   ```
3. Install packages with apt
   ```sh
   sudo apt install libsfml-dev make
   ```
4. Install build-essential if you don't have G++ or a C++ compiler 
   ```sh
   sudo apt install build-essential
   ```
5. Compile and run using the included Makefile
   ```sh
   `make`
   ```

This should be sufficient. Most of the build process is automated in the Makefile.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- USAGE EXAMPLES -->
## Usage

To run VisSort, use the compiled executable created by following the instructions in Getting Started. Currently, a windows release is not available, but it may be released in the future.
VisSort now supports several terminal flags, use --help or -h to see a list of them.

### Settings
The number of datapoints/bars can be edited using -c [number] or --count [number].

### Controls
The controls for the program are as follows:
ESC to scramble data, I for insertionSort, B for bogoSort, Q for quickSort, M for mergeSort, S for selectionSort, U for bubbleSort, and V to verify the current sortedness of the data.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- ROADMAP -->
## Roadmap

- [ ] Add more sorting algorithms
- [ ] Create standalone executable with data point count editing as a setting within
- [ ] Windows Release

See the [open issues](https://github.com/JacobNickerson/VisSort/issues) for a full list of proposed features (and known issues).

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTRIBUTING -->
## Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".
Don't forget to give the project a star! Thanks again!

1. Fork the Project
2. Create your Feature Branch (`git checkout -b feature/AmazingFeature`)
3. Commit your Changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the Branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

<p align="right">(<a href="#readme-top">back to top</a>)</p>

### Top contributors:

<a href="https://github.com/JacobNickerson/VisSort/graphs/contributors">
  <img src="https://contrib.rocks/image?repo=JacobNickerson/VisSort" alt="contrib.rocks image" />
</a>



<!-- LICENSE -->
## License

No license. I have no idea what's happening.

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- CONTACT -->
## Contact

Your Name - jacobnickerson817@gmail.com

Project Link: [https://github.com/JacobNickerson/VisSort](https://github.com/JacobNickerson/VisSort)

<p align="right">(<a href="#readme-top">back to top</a>)</p>



<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/JacobNickerson/VisSort.svg?style=for-the-badge
[contributors-url]: https://github.com/JacobNickerson/VisSort/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/JacobNickerson/VisSort.svg?style=for-the-badge
[forks-url]: https://github.com/JacobNickerson/VisSort/network/members
[stars-shield]: https://img.shields.io/github/stars/JacobNickerson/VisSort.svg?style=for-the-badge
[stars-url]: https://github.com/JacobNickerson/VisSort/stargazers
[issues-shield]: https://img.shields.io/github/issues/JacobNickerson/VisSort.svg?style=for-the-badge
[issues-url]: https://github.com/JacobNickerson/VisSort/issues
[license-shield]: https://img.shields.io/github/license/JacobNickerson/VisSort.svg?style=for-the-badge
[license-url]: https://github.com/JacobNickerson/VisSort/blob/master/LICENSE.txt
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/JacobNickerson817
[product-screenshot]: images/screenshot.png
[Isocpp.org]: https://img.shields.io/badge/C++-0769AD?style=for-the-badge&logo=cplusplus&logoColor=white
[C++-url]: https://isocpp.org/
[SFML-dev.org]: https://img.shields.io/badge/SFML-white?style=for-the-badge&logo=SFML&logoColor=8EC547
[SFML-url]: https://www.sfml-dev.org/
