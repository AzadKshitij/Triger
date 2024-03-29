# Triger

<p align="center">
  <img src="assets/Logos/TrigerLogoWithName.png" alt="Logo" />
</p>

Triger is primarily an early-stage interactive application and rendering engine for Windows. But working on making it cross plateform looking for contributors who can work on Linux version.

# Showcase
- ### 3D Viewport Camera
This camera is same as Blender's viewport camera

![3DViewPortCameraShowcase](./Showcase/GIF/3DViewPortCameraShowcase.gif)

- ### 3D Gizmo

![GizmoShowcase](./Showcase/GIF/GizmoShowcase.gif)

- ### Scene Loading and saving
- ### Batch render
- ### Rendering Stats

# Building

### Windows

1. Clone the repository recurcively to download all submodules with command

   ```bash
   git clone --recurse-submodules https://github.com/AzadKshitij/Triger.git
   ```

2. Generate Project for this open folder names **scripts** and run the [Generate-Win-Projects-VS2019](scripts/Generate-Win-Projects-VS2019.bat) file. It will create the solution file for the project.

3. **Open** and Build the solution( shorcut F7 ).

4. **Run** the solution ( Defalt starter project is **TrigerEditor** if you want to check **SandboxApp** change starter project to SandboxApp ).

# How to Contribute

1. First Read [Contribution Guide](https://github.com/AzadKshitij/Triger/blob/main/.github/CONTRIBUTING.md)
2. Clone repo and create a new branch:

```bash
 git clone --recurse-submodules https://github.com/AzadKshitij/Triger.git
 git checkout -b name_for_new_branch
```

3. Make changes and test

4. Submit Pull Request with comprehensive description of changes and a working GIF. Do follow the rules. Thaks For Your Contribution.
