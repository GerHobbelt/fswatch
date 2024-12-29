/*
 * Copyright (c) 2014-2024 Enrico M. Crisostomo
 *
 * This program is free software; you can redistribute it and/or modify it under
 * the terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more
 * details.
 *
 * You should have received a copy of the GNU General Public License along with
 * this program.  If not, see <http://www.gnu.org/licenses/>.
 */
/**
 * @file
 * @brief Header defining utility functions to manipulate paths.
 *
 * @copyright Copyright (c) 2014-2024 Enrico M. Crisostomo
 * @license GNU General Public License v. 3.0
 * @author Enrico M. Crisostomo
 * @version 1.8.0
 */

#ifndef FSW_PATH_UTILS_H
#  define FSW_PATH_UTILS_H

#  include <string>
#  include <vector>
#  include <filesystem>
#  include <sys/stat.h>

namespace fsw
{
  /**
   * @brief Gets a vector of direct directory entries.
   * 
   * @param path The directory whose entries must be returned.
   * @return A vector containing the list of entries of @p path.
   */
  std::vector<std::filesystem::directory_entry> get_directory_entries(const std::filesystem::path& path);
  
  /**
   * @brief Gets a vector of direct subdirectories.
   * 
   * @param path The directory whose subdirectories must be returned.
   * @return A vector containing the list of subdirectories of @p path.
   */
  std::vector<std::filesystem::directory_entry> get_subdirectories(const std::filesystem::path& path);

  /**
   * @brief Gets a vector of direct directory children.
   *
   * @param path The directory whose children must be returned.
   * @return A vector containing the list of children of @p path.
   */
  std::vector<std::string> get_directory_children(const std::string& path);

  /**
   * @brief Wraps a @c lstat(path, fd_stat) call that invokes @c perror() if it
   * fails.
   *
   * @param path The path to @c lstat().
   * @param fd_stat The @c stat structure where @c lstat() writes its results.
   * @return @c true if the function succeeds, @c false otherwise.
   */
  bool lstat_path(const std::string& path, struct stat& fd_stat);

  /**
   * @brief Wraps a @c stat(path, fd_stat) call that invokes @c perror() if it
   * fails.
   *
   * @param path The path to @c stat().
   * @param fd_stat The @c stat structure where @c stat() writes its results.
   * @return @c true if the function succeeds, @c false otherwise.
   */
  bool stat_path(const std::string& path, struct stat& fd_stat);
}
#endif  /* FSW_PATH_UTILS_H */
