##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=kurs
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=/home/stud/C++Projects/C++Projects
ProjectPath            :=/home/stud/C++Projects/C++Projects/kurs
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=
Date                   :=11/21/24
CodeLitePath           :=/home/stud/.codelite
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="kurs.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
CFLAGS   :=  -gdwarf-2 -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/User.cpp$(ObjectSuffix) $(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/SHA256.cpp$(ObjectSuffix) $(IntermediateDirectory)/UserDAtabase.cpp$(ObjectSuffix) $(IntermediateDirectory)/ClientHandler.cpp$(ObjectSuffix) $(IntermediateDirectory)/Errors.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/User.cpp$(ObjectSuffix): User.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/User.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/User.cpp$(DependSuffix) -MM User.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/kurs/User.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/User.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/User.cpp$(PreprocessSuffix): User.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/User.cpp$(PreprocessSuffix) User.cpp

$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/kurs/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/SHA256.cpp$(ObjectSuffix): SHA256.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/SHA256.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/SHA256.cpp$(DependSuffix) -MM SHA256.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/kurs/SHA256.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/SHA256.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/SHA256.cpp$(PreprocessSuffix): SHA256.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/SHA256.cpp$(PreprocessSuffix) SHA256.cpp

$(IntermediateDirectory)/UserDAtabase.cpp$(ObjectSuffix): UserDAtabase.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/UserDAtabase.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/UserDAtabase.cpp$(DependSuffix) -MM UserDAtabase.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/kurs/UserDAtabase.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/UserDAtabase.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/UserDAtabase.cpp$(PreprocessSuffix): UserDAtabase.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/UserDAtabase.cpp$(PreprocessSuffix) UserDAtabase.cpp

$(IntermediateDirectory)/ClientHandler.cpp$(ObjectSuffix): ClientHandler.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ClientHandler.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ClientHandler.cpp$(DependSuffix) -MM ClientHandler.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/kurs/ClientHandler.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ClientHandler.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ClientHandler.cpp$(PreprocessSuffix): ClientHandler.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ClientHandler.cpp$(PreprocessSuffix) ClientHandler.cpp

$(IntermediateDirectory)/Errors.cpp$(ObjectSuffix): Errors.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Errors.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Errors.cpp$(DependSuffix) -MM Errors.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/home/stud/C++Projects/C++Projects/kurs/Errors.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Errors.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Errors.cpp$(PreprocessSuffix): Errors.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Errors.cpp$(PreprocessSuffix) Errors.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


