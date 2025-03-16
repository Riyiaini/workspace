
union:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
_init():
    1000:	f3 0f 1e fa          	endbr64 
    1004:	48 83 ec 08          	sub    $0x8,%rsp
    1008:	48 8b 05 d9 2f 00 00 	mov    0x2fd9(%rip),%rax        # 3fe8 <__gmon_start__@Base>
    100f:	48 85 c0             	test   %rax,%rax
    1012:	74 02                	je     1016 <_init+0x16>
    1014:	ff d0                	call   *%rax
    1016:	48 83 c4 08          	add    $0x8,%rsp
    101a:	c3                   	ret    

Disassembly of section .plt:

0000000000001020 <.plt>:
    1020:	ff 35 9a 2f 00 00    	push   0x2f9a(%rip)        # 3fc0 <_GLOBAL_OFFSET_TABLE_+0x8>
    1026:	f2 ff 25 9b 2f 00 00 	bnd jmp *0x2f9b(%rip)        # 3fc8 <_GLOBAL_OFFSET_TABLE_+0x10>
    102d:	0f 1f 00             	nopl   (%rax)
    1030:	f3 0f 1e fa          	endbr64 
    1034:	68 00 00 00 00       	push   $0x0
    1039:	f2 e9 e1 ff ff ff    	bnd jmp 1020 <_init+0x20>
    103f:	90                   	nop

Disassembly of section .plt.got:

0000000000001040 <__cxa_finalize@plt>:
    1040:	f3 0f 1e fa          	endbr64 
    1044:	f2 ff 25 ad 2f 00 00 	bnd jmp *0x2fad(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    104b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .plt.sec:

0000000000001050 <__printf_chk@plt>:
    1050:	f3 0f 1e fa          	endbr64 
    1054:	f2 ff 25 75 2f 00 00 	bnd jmp *0x2f75(%rip)        # 3fd0 <__printf_chk@GLIBC_2.3.4>
    105b:	0f 1f 44 00 00       	nopl   0x0(%rax,%rax,1)

Disassembly of section .text:

0000000000001060 <_start>:
_start():
    1060:	f3 0f 1e fa          	endbr64 
    1064:	31 ed                	xor    %ebp,%ebp
    1066:	49 89 d1             	mov    %rdx,%r9
    1069:	5e                   	pop    %rsi
    106a:	48 89 e2             	mov    %rsp,%rdx
    106d:	48 83 e4 f0          	and    $0xfffffffffffffff0,%rsp
    1071:	50                   	push   %rax
    1072:	54                   	push   %rsp
    1073:	45 31 c0             	xor    %r8d,%r8d
    1076:	31 c9                	xor    %ecx,%ecx
    1078:	48 8d 3d ca 00 00 00 	lea    0xca(%rip),%rdi        # 1149 <main>
    107f:	ff 15 53 2f 00 00    	call   *0x2f53(%rip)        # 3fd8 <__libc_start_main@GLIBC_2.34>
    1085:	f4                   	hlt    
    1086:	66 2e 0f 1f 84 00 00 	cs nopw 0x0(%rax,%rax,1)
    108d:	00 00 00 

0000000000001090 <deregister_tm_clones>:
deregister_tm_clones():
    1090:	48 8d 3d 79 2f 00 00 	lea    0x2f79(%rip),%rdi        # 4010 <__TMC_END__>
    1097:	48 8d 05 72 2f 00 00 	lea    0x2f72(%rip),%rax        # 4010 <__TMC_END__>
    109e:	48 39 f8             	cmp    %rdi,%rax
    10a1:	74 15                	je     10b8 <deregister_tm_clones+0x28>
    10a3:	48 8b 05 36 2f 00 00 	mov    0x2f36(%rip),%rax        # 3fe0 <_ITM_deregisterTMCloneTable@Base>
    10aa:	48 85 c0             	test   %rax,%rax
    10ad:	74 09                	je     10b8 <deregister_tm_clones+0x28>
    10af:	ff e0                	jmp    *%rax
    10b1:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)
    10b8:	c3                   	ret    
    10b9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

00000000000010c0 <register_tm_clones>:
register_tm_clones():
    10c0:	48 8d 3d 49 2f 00 00 	lea    0x2f49(%rip),%rdi        # 4010 <__TMC_END__>
    10c7:	48 8d 35 42 2f 00 00 	lea    0x2f42(%rip),%rsi        # 4010 <__TMC_END__>
    10ce:	48 29 fe             	sub    %rdi,%rsi
    10d1:	48 89 f0             	mov    %rsi,%rax
    10d4:	48 c1 ee 3f          	shr    $0x3f,%rsi
    10d8:	48 c1 f8 03          	sar    $0x3,%rax
    10dc:	48 01 c6             	add    %rax,%rsi
    10df:	48 d1 fe             	sar    %rsi
    10e2:	74 14                	je     10f8 <register_tm_clones+0x38>
    10e4:	48 8b 05 05 2f 00 00 	mov    0x2f05(%rip),%rax        # 3ff0 <_ITM_registerTMCloneTable@Base>
    10eb:	48 85 c0             	test   %rax,%rax
    10ee:	74 08                	je     10f8 <register_tm_clones+0x38>
    10f0:	ff e0                	jmp    *%rax
    10f2:	66 0f 1f 44 00 00    	nopw   0x0(%rax,%rax,1)
    10f8:	c3                   	ret    
    10f9:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001100 <__do_global_dtors_aux>:
__do_global_dtors_aux():
    1100:	f3 0f 1e fa          	endbr64 
    1104:	80 3d 05 2f 00 00 00 	cmpb   $0x0,0x2f05(%rip)        # 4010 <__TMC_END__>
    110b:	75 2b                	jne    1138 <__do_global_dtors_aux+0x38>
    110d:	55                   	push   %rbp
    110e:	48 83 3d e2 2e 00 00 	cmpq   $0x0,0x2ee2(%rip)        # 3ff8 <__cxa_finalize@GLIBC_2.2.5>
    1115:	00 
    1116:	48 89 e5             	mov    %rsp,%rbp
    1119:	74 0c                	je     1127 <__do_global_dtors_aux+0x27>
    111b:	48 8b 3d e6 2e 00 00 	mov    0x2ee6(%rip),%rdi        # 4008 <__dso_handle>
    1122:	e8 19 ff ff ff       	call   1040 <__cxa_finalize@plt>
    1127:	e8 64 ff ff ff       	call   1090 <deregister_tm_clones>
    112c:	c6 05 dd 2e 00 00 01 	movb   $0x1,0x2edd(%rip)        # 4010 <__TMC_END__>
    1133:	5d                   	pop    %rbp
    1134:	c3                   	ret    
    1135:	0f 1f 00             	nopl   (%rax)
    1138:	c3                   	ret    
    1139:	0f 1f 80 00 00 00 00 	nopl   0x0(%rax)

0000000000001140 <frame_dummy>:
frame_dummy():
    1140:	f3 0f 1e fa          	endbr64 
    1144:	e9 77 ff ff ff       	jmp    10c0 <register_tm_clones>

0000000000001149 <main>:
main():
    1149:	f3 0f 1e fa          	endbr64 
    114d:	48 83 ec 08          	sub    $0x8,%rsp
    1151:	b8 00 00 00 00       	mov    $0x0,%eax
    1156:	eb 14                	jmp    116c <main+0x23>
    1158:	8d 70 f0             	lea    -0x10(%rax),%esi
    115b:	48 63 d0             	movslq %eax,%rdx
    115e:	48 8d 0d b3 2e 00 00 	lea    0x2eb3(%rip),%rcx        # 4018 <dw>
    1165:	40 88 34 11          	mov    %sil,(%rcx,%rdx,1)
    1169:	83 c0 01             	add    $0x1,%eax
    116c:	83 f8 07             	cmp    $0x7,%eax
    116f:	7e e7                	jle    1158 <main+0xf>
    1171:	44 0f b6 05 a6 2e 00 	movzbl 0x2ea6(%rip),%r8d        # 401f <dw+0x7>
    1178:	00 
    1179:	0f b6 3d 9e 2e 00 00 	movzbl 0x2e9e(%rip),%edi        # 401e <dw+0x6>
    1180:	0f b6 35 96 2e 00 00 	movzbl 0x2e96(%rip),%esi        # 401d <dw+0x5>
    1187:	0f b6 05 8e 2e 00 00 	movzbl 0x2e8e(%rip),%eax        # 401c <dw+0x4>
    118e:	0f b6 0d 84 2e 00 00 	movzbl 0x2e84(%rip),%ecx        # 4019 <dw+0x1>
    1195:	0f b6 15 7c 2e 00 00 	movzbl 0x2e7c(%rip),%edx        # 4018 <dw>
    119c:	41 50                	push   %r8
    119e:	57                   	push   %rdi
    119f:	56                   	push   %rsi
    11a0:	50                   	push   %rax
    11a1:	44 0f b6 0d 72 2e 00 	movzbl 0x2e72(%rip),%r9d        # 401b <dw+0x3>
    11a8:	00 
    11a9:	44 0f b6 05 69 2e 00 	movzbl 0x2e69(%rip),%r8d        # 401a <dw+0x2>
    11b0:	00 
    11b1:	48 8d 35 50 0e 00 00 	lea    0xe50(%rip),%rsi        # 2008 <_IO_stdin_used+0x8>
    11b8:	bf 01 00 00 00       	mov    $0x1,%edi
    11bd:	b8 00 00 00 00       	mov    $0x0,%eax
    11c2:	e8 89 fe ff ff       	call   1050 <__printf_chk@plt>
    11c7:	0f b7 0d 4c 2e 00 00 	movzwl 0x2e4c(%rip),%ecx        # 401a <dw+0x2>
    11ce:	0f b7 15 43 2e 00 00 	movzwl 0x2e43(%rip),%edx        # 4018 <dw>
    11d5:	48 83 c4 20          	add    $0x20,%rsp
    11d9:	44 0f b7 0d 3d 2e 00 	movzwl 0x2e3d(%rip),%r9d        # 401e <dw+0x6>
    11e0:	00 
    11e1:	44 0f b7 05 33 2e 00 	movzwl 0x2e33(%rip),%r8d        # 401c <dw+0x4>
    11e8:	00 
    11e9:	48 8d 35 60 0e 00 00 	lea    0xe60(%rip),%rsi        # 2050 <_IO_stdin_used+0x50>
    11f0:	bf 01 00 00 00       	mov    $0x1,%edi
    11f5:	b8 00 00 00 00       	mov    $0x0,%eax
    11fa:	e8 51 fe ff ff       	call   1050 <__printf_chk@plt>
    11ff:	8b 0d 17 2e 00 00    	mov    0x2e17(%rip),%ecx        # 401c <dw+0x4>
    1205:	8b 15 0d 2e 00 00    	mov    0x2e0d(%rip),%edx        # 4018 <dw>
    120b:	48 8d 35 6e 0e 00 00 	lea    0xe6e(%rip),%rsi        # 2080 <_IO_stdin_used+0x80>
    1212:	bf 01 00 00 00       	mov    $0x1,%edi
    1217:	b8 00 00 00 00       	mov    $0x0,%eax
    121c:	e8 2f fe ff ff       	call   1050 <__printf_chk@plt>
    1221:	48 8b 15 f0 2d 00 00 	mov    0x2df0(%rip),%rdx        # 4018 <dw>
    1228:	48 8d 35 72 0e 00 00 	lea    0xe72(%rip),%rsi        # 20a1 <_IO_stdin_used+0xa1>
    122f:	bf 01 00 00 00       	mov    $0x1,%edi
    1234:	b8 00 00 00 00       	mov    $0x0,%eax
    1239:	e8 12 fe ff ff       	call   1050 <__printf_chk@plt>
    123e:	b8 00 00 00 00       	mov    $0x0,%eax
    1243:	48 83 c4 08          	add    $0x8,%rsp
    1247:	c3                   	ret    

Disassembly of section .fini:

0000000000001248 <_fini>:
_fini():
    1248:	f3 0f 1e fa          	endbr64 
    124c:	48 83 ec 08          	sub    $0x8,%rsp
    1250:	48 83 c4 08          	add    $0x8,%rsp
    1254:	c3                   	ret    
