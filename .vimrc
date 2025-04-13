" vim base config
set nocompatible
syntax on
set showmode
set t_Co=256
filetype indent on
set expandtab
set autoindent
let mapleader = ','
set number  			" 显示行号
set incsearch           " 实时开启搜索高亮
set hlsearch			" 搜索结果高亮
set autoindent			" 自动缩进
set smartindent			" 智能缩进
set tabstop=4			" 设置tab制表符号所占宽度为4
set softtabstop=4		" 设置按tab时缩进宽度为4
set shiftwidth=4		" 设置自动缩进宽度为4
set expandtab			" 缩进时将tab制表服转为空格
set smartcase           " 开启智能大小写查找
set encoding=utf-8      " Use UTF-8.
set showcmd             " Display incomplete commands.
set clipboard=unnamedplus " 开启系统剪切板
set cursorline          " 高亮当前行
set ignorecase          " 设置忽略大小写
set smartcase           " 设置智能大小写
set ruler               " 设置显示当前位置
" vim plug
call plug#begin()
Plug 'crusoexia/vim-monokai'
Plug 'neoclide/coc.nvim', {'branch': 'release'}
Plug 'jiangmiao/auto-pairs'
Plug 'rhysd/vim-clang-format'
Plug 'Yggdroot/indentLine'
Plug 'cdelledonne/vim-cmake'
Plug 'vim-airline/vim-airline'
Plug 'vim-airline/vim-airline-themes'
Plug 'octol/vim-cpp-enhanced-highlight'
Plug 'rust-lang/rust.vim'
Plug 'majutsushi/tagbar' 
Plug 'scrooloose/nerdtree'
" NERDCommenter
Plug 'scrooloose/nerdcommenter'
Plug 'rrethy/vim-illuminate'
call plug#end()

"  theme
colorscheme monokai
" Clang Format
let g:clang_format#code_style='WebKit'
nnoremap <C-S-i> :ClangFormat<CR>


" =================================== Coc Config ==================
" Use tab for trigger completion with characters ahead and navigate
" NOTE: There's always complete item selected by default, you may want to enable
" no select by `"suggest.noselect": true` in your configuration file
" NOTE: Use command ':verbose imap <tab>' to make sure tab is not mapped by
" other plugin before putting this into your config
inoremap <silent><expr> <TAB>
      \ coc#pum#visible() ? coc#pum#next(1) :
      \ CheckBackspace() ? "\<Tab>" :
      \ coc#refresh()
inoremap <expr><S-TAB> coc#pum#visible() ? coc#pum#prev(1) : "\<C-h>"

" Make <CR> to accept selected completion item or notify coc.nvim to format
" <C-g>u breaks current undo, please make your own choice
inoremap <silent><expr> <CR> coc#pum#visible() ? coc#pum#confirm()
                              \: "\<C-g>u\<CR>\<c-r>=coc#on_enter()\<CR>"

function! CheckBackspace() abort
  let col = col('.') - 1
  return !col || getline('.')[col - 1]  =~# '\s'
endfunction

" Use <c-space> to trigger completion
if has('nvim')
  inoremap <silent><expr> <c-space> coc#refresh()
else
  inoremap <silent><expr> <c-@> coc#refresh()
endif

" Use `[g` and `]g` to navigate diagnostics
" Use `:CocDiagnostics` to get all diagnostics of current buffer in location list
nmap <silent> [g <Plug>(coc-diagnostic-prev)
nmap <silent> ]g <Plug>(coc-diagnostic-next)

" GoTo code navigation
nmap <silent> gd <Plug>(coc-definition)
nmap <silent> gy <Plug>(coc-type-definition)
nmap <silent> gi <Plug>(coc-implementation)
nmap <silent> gr <Plug>(coc-references)

nmap <C-l> :w<CR>:b#<CR>
nmap <C-L> :w<CR>:e#<CR>
" Use K to show documentation in preview window
nnoremap <silent> K :call ShowDocumentation()<CR>

function! ShowDocumentation()
  if CocAction('hasProvider', 'hover')
    call CocActionAsync('doHover')
  else
    call feedkeys('K', 'in')
  endif
endfunction

" Highlight the symbol and its references when holding the cursor
autocmd CursorHold * silent call CocActionAsync('highlight')

" Symbol renaming
nmap <leader>rn <Plug>(coc-rename)

" Formatting selected code
xmap <leader>f  <Plug>(coc-format-selected)
nmap <leader>f  <Plug>(coc-format-selected)

augroup mygroup
  autocmd!
  " Setup formatexpr specified filetype(s)
  autocmd FileType typescript,json setl formatexpr=CocAction('formatSelected')
  " Update signature help on jump placeholder
  autocmd User CocJumpPlaceholder call CocActionAsync('showSignatureHelp')
augroup end

" Applying code actions to the selected code block
" Example: `<leader>aap` for current paragraph
xmap <leader>a  <Plug>(coc-codeaction-selected)
nmap <leader>a  <Plug>(coc-codeaction-selected)

" Remap keys for applying code actions at the cursor position
nmap <leader>ac  <Plug>(coc-codeaction-cursor)
" Remap keys for apply code actions affect whole buffer
nmap <leader>as  <Plug>(coc-codeaction-source)
" Apply the most preferred quickfix action to fix diagnostic on the current line
nmap <leader>qf  <Plug>(coc-fix-current)

" Remap keys for applying refactor code actions
nmap <silent> <leader>re <Plug>(coc-codeaction-refactor)
xmap <silent> <leader>r  <Plug>(coc-codeaction-refactor-selected)
nmap <silent> <leader>r  <Plug>(coc-codeaction-refactor-selected)

" Run the Code Lens action on the current line
nmap <leader>cl  <Plug>(coc-codelens-action)

" Map function and class text objects
" NOTE: Requires 'textDocument.documentSymbol' support from the language server
xmap if <Plug>(coc-funcobj-i)
omap if <Plug>(coc-funcobj-i)
xmap af <Plug>(coc-funcobj-a)
omap af <Plug>(coc-funcobj-a)
xmap ic <Plug>(coc-classobj-i)
omap ic <Plug>(coc-classobj-i)
xmap ac <Plug>(coc-classobj-a)
omap ac <Plug>(coc-classobj-a)

" Remap <C-f> and <C-b> to scroll float windows/popups
if has('nvim-0.4.0') || has('patch-8.2.0750')
  nnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
  nnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
  inoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? "\<c-r>=coc#float#scroll(1)\<cr>" : "\<Right>"
  inoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? "\<c-r>=coc#float#scroll(0)\<cr>" : "\<Left>"
  vnoremap <silent><nowait><expr> <C-f> coc#float#has_scroll() ? coc#float#scroll(1) : "\<C-f>"
  vnoremap <silent><nowait><expr> <C-b> coc#float#has_scroll() ? coc#float#scroll(0) : "\<C-b>"
endif

" Use CTRL-S for selections ranges
" Requires 'textDocument/selectionRange' support of language server
nmap <silent> <C-s> <Plug>(coc-range-select)
xmap <silent> <C-s> <Plug>(coc-range-select)

" Add `:Format` command to format current buffer
command! -nargs=0 Format :call CocActionAsync('format')

" Add `:Fold` command to fold current buffer
command! -nargs=? Fold :call     CocAction('fold', <f-args>)

" Add `:OR` command for organize imports of the current buffer
command! -nargs=0 OR   :call     CocActionAsync('runCommand', 'editor.action.organizeImport')

" Add (Neo)Vim's native statusline support
" NOTE: Please see `:h coc-status` for integrations with external plugins that
" provide custom statusline: lightline.vim, vim-airline
set statusline^=%{coc#status()}%{get(b:,'coc_current_function','')}

" Mappings for CoCList
" Show all diagnostics
nnoremap <silent><nowait> <space>a  :<C-u>CocList diagnostics<cr>
" Manage extensions
nnoremap <silent><nowait> <space>e  :<C-u>CocList extensions<cr>
" Show commands
nnoremap <silent><nowait> <space>c  :<C-u>CocList commands<cr>
" Find symbol of current document
nnoremap <silent><nowait> <space>o  :<C-u>CocList outline<cr>
" Search workspace symbols
nnoremap <silent><nowait> <space>s  :<C-u>CocList -I symbols<cr>
" Do default action for next item
nnoremap <silent><nowait> <space>j  :<C-u>CocNext<CR>
" Do default action for previous item
nnoremap <silent><nowait> <space>k  :<C-u>CocPrev<CR>
" Resume latest coc list
nnoremap <silent><nowait> <space>p  :<C-u>CocListResume<CR>


"==========cpp highlight"
let g:cpp_class_scope_highlight = 1
let g:cpp_member_variable_highlight = 1
let g:cpp_class_decl_highlight = 1
let g:cpp_experimental_tmplate_highlight = 1
let g:cpp_concepts__highlight = 1
"hi illuminatedWord ctermfg=white ctermbg=99
"--------------------------------------------------------------------------
"vim-airline
"--------------------------------------------------------------------------
" airline
let g:airline#extensions#tabline#enabled = 1                " 设置允许修改默认tab样式
let g:airline#extensions#tabline#formatter = 'jsformatter'  " 设置默认tab栏样式

" airline-theme
"let g:airline_theme='solarized'
let g:airline_theme='angr'    " 好像还是比较喜欢这个颜色



"============== Configure the Tagbar plugin mapping button=================
" Set the plug-in of ctags used by tagbar
let g:tagbar_ctags_bin='/usr/bin/ctags'
" Key F4: Shrink/Expand Tagbar Window
map <F4> :TagbarToggle<CR>
" Set the window width of tagbar to 25
let g:tagbar_width = 25
" Append the C/C++standard library header file to tags
set tags+=/usr/include/tags
" Open the tagbar automatically when opening the file
autocmd BufReadPost *.cpp,*.c,*.h,*.cc,*.cxx call tagbar#autoopen()

"+++++++++++++++ Configure the NERDTree plugin mapping button++++++++++++++
" Automatically open NERDTree after opening the file
"autocmd VimEnter * NERDTree
" Key F2: Map other tabs
map <F2> :NERDTreeMirror<CR>
" Key F3: Expand/shrink NERDTree
map <F3> :NERDTreeToggle<CR>
" Key f: In the NERDTree window, jump the cursor to the currently open file.
map f :NERDTreeFind<CR>
" Key 1: Switch to the previous tab
map 1 :tabp<CR>
" Key 2: Switch to the next tab
map 2 :tabn<CR>
let g:python_host_prog = "usr/bin/python"

"++++++++++++++++++++++++++++按键映射+++++++++++++++++++++++
" 编译并运行C++程序（通用配置）
nnoremap <F5> :w<CR>:!g++ -std=c++2a % -o %< && ./%<<CR>




"==================粘贴+++++++++++
" ~/.vimrc
if executable('/mnt/c/Windows/System32/clip.exe')
    augroup WSLYank
        autocmd!
        autocmd TextYankPost * if v:event.operator ==# 'y' | call system('/mnt/c/Windows/System32/clip.exe', @0) | endif
    augroup END
endif
